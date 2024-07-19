/*
** EPITECH PROJECT, 2023
** r-type_client
** File description:
** Client.cpp
*/

#include "Client.hpp"
#include "PacketCallbacks.hpp"
#include "Systems.hpp"
#include <utility>
#include "ClientComponents.hpp"
#include "ClientSystems.hpp"

namespace client {

    /**
     * Client
     * Constructor of Client
     */
    Client::Client() : _server_list(), _network(_network_handler), _packets_registry(), _network_handler(_server_list, _packets_registry),
                        _server(nullptr), _connected(false), _ecs(), _renderer(_ecs), _current_player_id(0), _timed_events()
    {
    }

    /**
     * ~Client
     * Destructor of Client
     */
    Client::~Client()
    {
    }

    /**
     * connectToServer
     * Connect to the server
     * @param address
     * @param port
     */
    void Client::connectToServer(std::string address, int port)
    {
        registerPacketClient(EPacketClient::CLIENT_HELLO);
        auto first_data = _network_handler.serializePacket<network::GenericPacket<std::any>>(EPacketClient::CLIENT_HELLO);
        _network.run(std::move(address), port, *first_data);
    }

    /**
     * runClient
     * Run the client
     */
    void Client::runClient()
    {
        float deltatime = 0;

        setup(deltatime);
        _renderer.startRender();
        while (_renderer.isOpen()) {
            networkHandle();
            _ecs.runSystems();
            _timed_events.runEvents(deltatime);
            deltatime = _renderer.render();
        }
        _network.stop();
    }

    /**
     * networkHandle
     * Handle the network
     */
    void Client::networkHandle()
    {
            while (!_network_handler.isPacketQueueEmpty()) {
                _server = &_server_list.begin()->second;
                try {
                    _network_handler.threatPacket();
                } catch (std::exception &e) {
                    std::cerr << "invalid packet from server: " << e.what() << std::endl;
                }
            }
            try {
                _network_handler.runPackets();
            } catch (std::exception &e) {
                std::cerr << "invalid packet from server: " << e.what() << std::endl;
            }
    }

    /**
     * getPacketsRegistry
     * Get the packets registry
     * @return
     */
    network::PacketsRegistry &Client::getPacketsRegistry()
    {
        return _packets_registry;
    }

    /**
     * getNetworkHandler
     * Get the network handler
     * @return
     */
    network::NetworkHandler<EPacketServer> &Client::getNetworkHandler()
    {
        return _network_handler;
    }

    /**
     * setup
     * Setup the client (register components, systems and network packets)
     * @param deltatime
     */
    void Client::setup(float &deltatime)
    {
        registerPacketClient<std::string>(EPacketClient::DEBUG_PACKET_CLIENT);
        registerPacketClient<components::Position, components::Velocity>(EPacketClient::CLIENT_SEND_POS_VEL);
        registerPacketClient(EPacketClient::SHOOT_BULLET);

        registerPacketServer<bool>(PacketCallbacks::helloCallback, EPacketServer::SERVER_HELLO);
        registerPacketServer<std::string>(PacketCallbacks::debugCallback, EPacketServer::DEBUG_PACKET_SERVER);
        registerPacketServer<int, components::Position>(PacketCallbacks::newClientCallback, EPacketServer::NOTIFY_NEW_CLIENT);
        registerPacketServer<int, components::Position>(PacketCallbacks::clientBaseInfoCallback, EPacketServer::CLIENT_BASE_INFO);
        registerPacketServer<int, components::Position, components::Velocity>(PacketCallbacks::forceSetPosCallback, EPacketServer::FORCE_SET_POS_VEL);
        registerPacketServer<int, components::Position, components::Velocity>(PacketCallbacks::sendPosVelCallback, EPacketServer::SEND_POS_VEL);
        registerPacketServer<int>(PacketCallbacks::playerShootCallback, EPacketServer::PLAYER_SHOOT_BULLET);
        registerPacketServer<int, components::Position>(PacketCallbacks::spawnEnemyCallback, EPacketServer::SPAWN_ENEMY);
        registerPacketServer<int, components::Position, components::Velocity, bool>(PacketCallbacks::moveEnemyCallback, EPacketServer::MOVE_ENEMY);
        registerPacketServer<int>(PacketCallbacks::enemyShootCallback, EPacketServer::SHOOT_ENEMY);

        _ecs.registerComponent<components::Position>();
        _ecs.registerComponent<components::Velocity>();
        _ecs.registerComponent<components::Anim>();
        _ecs.registerComponent<components::MissileStruct>();
        _ecs.registerComponent<Loader *>();
        _ecs.registerComponent<components::Id>();
        _ecs.registerComponent<components::Drawable>();
        _ecs.registerComponent<components::Size>();
        _ecs.registerComponent<components::Event>();
        _ecs.registerComponent<components::Window>();
        _ecs.registerComponent<components::EventQueues>();
        _ecs.registerComponent<components::EntityType>();
        _ecs.registerComponent<components::NetworkHandler>();
        _ecs.registerComponent<components::LastVelocity>();
        _ecs.registerComponent<components::Enemy>();
        _ecs.registerComponent<components::EnemySpawnData>();
        _ecs.registerComponent<components::playerData>();

        _ecs.addSystem<components::Position, components::Velocity>(ecs::Systems::moveSystem, deltatime);
        _ecs.addSystem<components::Position, components::Drawable, components::Size, components::Enemy, components::Velocity>(ecs::ClientSystems::drawSystem, deltatime);
        _ecs.addSystem<components::Event, components::Window, components::EventQueues>(ecs::ClientSystems::eventPollingSystem);
        _ecs.addSystem<components::Window, components::EventQueues>(ecs::ClientSystems::windowEventsSystem);
        _ecs.addSystem<components::EventQueues, components::Velocity, components::EntityType, components::Position>(ecs::ClientSystems::playerMoveEvent);
        _ecs.addSystem<components::Velocity, components::Position, components::EntityType, components::NetworkHandler, components::LastVelocity>(ecs::ClientSystems::playerMoveNetwork, deltatime);
        setupBackground();
        _ecs.addSystem<components::EventQueues, components::Velocity, components::EntityType, components::Position>(ecs::ClientSystems::playerMoveEvent);
        _ecs.addSystem<components::Drawable, components::Anim>(ecs::ClientSystems::spriteAnimation, deltatime);
        _ecs.addSystem<components::MissileStruct>(ecs::Systems::manageMissiles, deltatime);
        _ecs.addSystem<components::EntityType, components::Position, components::Size, components::playerData, components::Enemy>(ecs::Systems::manageHitBox, deltatime);
        _ecs.addSystem<components::Enemy, components::EnemySpawnData>(ecs::Systems::enemyDeath, deltatime);
        _ecs.addSystem<components::playerData>(ecs::Systems::playerDeath, deltatime);

        auto entity(_ecs.spawnEntity());
        _ecs.addComponent(entity, &_texturesFonts);
    }

    /**
     * isConnected
     * Check if the client is connected
     * @return bool
     */
    bool Client::isConnected() const
    {
        return _connected;
    }

    /**
     * setConnected
     * Set the connected status
     * @param connected
     */
    void Client::setConnected(bool connected)
    {
        _connected = connected;
    }

    /**
     * registerNewPlayer
     * Register a new player
     * @param id
     * @param pos
     */
    void Client::registerNewPlayer(int id, components::Position pos)
    {
        auto entity(_ecs.spawnEntity());

        _ecs.addComponent(entity, components::Position{pos.x, pos.y});
        _ecs.addComponent(entity, components::Velocity{0, 0});
        _ecs.addComponent(entity, components::LastVelocity{0, 0});
        _ecs.addComponent(entity, components::Id{id});
        _ecs.addComponent(entity, components::playerData{0.5, 0.0, 5, 0});

        std::map<int, sf::IntRect> spriteRects;
        for (int i = 0; i < 5; ++i)
            spriteRects[i] = sf::IntRect(i * 58, 0, 58, 40);

        int n = id;
        for (; n > 4;)
            n -= 5;

        _ecs.addComponent(entity, components::Anim{5, 0, 0.1f, 0.0f, spriteRects});
        _ecs.addComponent(entity, components::Drawable(_texturesFonts.getTexture("player" + std::to_string(n + 1))));
        _ecs.addComponent(entity, components::Size{58, 40});
        _ecs.addComponent(entity, components::EntityType{components::EntityType::PLAYER});
    }

    /**
     * setupBackground
     * Setup the background
     */
    void Client::setupBackground()
    {
        auto entity = _ecs.spawnEntity();

        _ecs.addComponent(entity, components::Position{0, 0});
        _ecs.addComponent(entity, components::Velocity{-500, 0});
        _ecs.addComponent(entity, components::Drawable{_texturesFonts.getTexture("background")});
        _ecs.addComponent(entity, components::Size{3840, 1080});
        _ecs.addComponent(entity, components::EntityType{components::EntityType::BACKGROUND});
    }

    /**
     * getEcs
     * Get the ECS
     * @return
     */
    Registry &Client::getEcs()
    {
        return _ecs;
    }

    /**
     * setCurrentPlayer
     * Set the current player
     * @param id
     */
    void Client::setCurrentPlayer(int id)
    {
        auto &ids = getEcs().getComponent<components::Id>();
        auto &entity_types = getEcs().getComponent<components::EntityType>();

        for (auto entity : getEcs().getEntities()) {
            if (ids.has_index(entity) && entity_types.has_index(entity) && ids[entity] == id) {
                entity_types[entity] = components::EntityType::CURRENT_PLAYER;
                _ecs.addComponent(entity, &_network_handler);
                _current_player_id = id;
                break;
            }
        }
    }

    void Client::createEnemy(components::Position pos, int id)
    {
        auto loaderTmp = _ecs.getComponent<Loader *>();
        Loader *loader;
        for (int i = 0; i < loaderTmp.size(); ++i)
        {
            if (loaderTmp.has_index(i))
            {
                loader = loaderTmp[i].value();
                break;
            }
        }
        if (!loader)
            return;
        auto enemy(_ecs.spawnEntity());
        _ecs.addComponent(enemy, components::Position{pos});
        _ecs.addComponent(enemy, components::Velocity{0, 0});
        _ecs.addComponent(enemy, components::Enemy{2, 1, 0.0f, id});
        std::map<int, sf::IntRect> spriteRects;
        for (int v = 0; v < 3; ++v)
            spriteRects[v] = sf::IntRect(v * 55, 0, 55, 55);
        sf::Sprite tmp(loader->getTexture("enemy"));
        tmp.setTextureRect(spriteRects[0]);
        _ecs.addComponent(enemy, components::Anim{3, 0, 0.2f, 0.0f, spriteRects});
        _ecs.addComponent(enemy, components::Drawable(tmp));
        _ecs.addComponent(enemy, components::Size{160.6, 214});
        _ecs.addComponent(enemy, components::EntityType{components::EntityType::ENEMY});

    }

    void Client::createBoss(components::Position pos)
    {
        auto loaderTmp = _ecs.getComponent<Loader *>();
        Loader *loader;
        for (int i = 0; i < loaderTmp.size(); ++i)
        {
            if (loaderTmp.has_index(i))
            {
                loader = loaderTmp[i].value();
                break;
            }
        }
        if (!loader)
            return;
        auto enemy(_ecs.spawnEntity());
        _ecs.addComponent(enemy, components::Position{pos});
        _ecs.addComponent(enemy, components::Velocity{0, 0});
        _ecs.addComponent(enemy, components::Enemy{2, 1, 0.0f});
        std::map<int, sf::IntRect> spriteRects;
        for (int v = 0; v < 3; ++v)
            spriteRects[v] = sf::IntRect(v * 55, 0, 55, 55);
        sf::Sprite tmp(loader->getTexture("enemy"));
        tmp.setTextureRect(spriteRects[0]);
        _ecs.addComponent(enemy, components::Anim{3, 0, 0.1f, 0.0f, spriteRects});
        _ecs.addComponent(enemy, components::Drawable(tmp));
        _ecs.addComponent(enemy, components::Size{55, 55});
        _ecs.addComponent(enemy, components::EntityType{components::EntityType::ENEMY});
    }

    void Client::createPlayerMissile(components::Id id)
    {
        auto &ids = getEcs().getComponent<components::Id>();
        auto &entity_types = getEcs().getComponent<components::EntityType>();
        auto &poss = getEcs().getComponent<components::Position>();

        for (auto entity : getEcs().getEntities()) {
            if (ids.has_index(entity) && entity_types.has_index(entity) && ids[entity] == id) {
                auto pos = poss[entity].value();
                auto loaderTmp = _ecs.getComponent<Loader *>();
                Loader *loader;


                for (int i = 0; i < loaderTmp.size(); ++i) {
                    if (loaderTmp.has_index(i)) {
                        loader = loaderTmp[i].value();
                        break;
                    }
                }
                if (!loader)
                    return;

                auto missile (_ecs.spawnEntity());

                _ecs.addComponent(missile, components::Position{pos.x + 40, pos.y});
                _ecs.addComponent(missile, components::Velocity{200, 0});

                std::map<int, sf::IntRect> spriteRects;
                for (int i = 0; i < 6; ++i)
                    spriteRects[i] = sf::IntRect(i * 30, 0, 30, 30);
                _ecs.addComponent(missile, components::MissileStruct{0.0f, true});
                sf::Sprite tmp (loader->getTexture("missile"));
                tmp.setTextureRect(spriteRects[0]);

                _ecs.addComponent(missile, components::Anim{6, 0, 0.1f, 0.0f, spriteRects});
                _ecs.addComponent(missile, components::Drawable(tmp));
                _ecs.addComponent(missile, components::Size{30, 30});
                _ecs.addComponent(missile, components::EntityType{components::EntityType::BULLET});
                break;
            }
        }
    }

    void Client::spawnEnemyMissile(int enemyIndex, float x, float y)
    {
        auto loaderTmp = _ecs.getComponent<Loader *>();
        Loader *loader;

        for (int i = 0; i < loaderTmp.size(); ++i)
        {
            if (loaderTmp.has_index(i))
            {
                loader = loaderTmp[i].value();
                break;
            }
        }
        if (!loader)
            return;

        auto missile(_ecs.spawnEntity());

        _ecs.addComponent(missile, components::Position{x - 40, y});
        _ecs.addComponent(missile, components::Velocity{-200, 0});

        std::map<int, sf::IntRect> spriteRects;
        for (int i = 0; i < 3; ++i)
            spriteRects[i] = sf::IntRect(i * 35, 0, 35, 35);
        _ecs.addComponent(missile, components::MissileStruct{0.0f, true});
        sf::Sprite tmp(loader->getTexture("enemymissile"));
        tmp.setTextureRect(spriteRects[0]);

        _ecs.addComponent(missile, components::Anim{3, 0, 0.1f, 0.0f, spriteRects});
        _ecs.addComponent(missile, components::Drawable(tmp));
        _ecs.addComponent(missile, components::Size{35, 35});
        _ecs.addComponent(missile, components::EntityType{components::EntityType::ENEMYBULLET}); // Adjust entity type as needed
    }


} // client