/*
** EPITECH PROJECT, 2023
** base
** File description:
** base
*/

#ifndef PROCESS_HPP
    #define PROCESS_HPP

    #include "base.hpp"
    #include "utils.hpp"

class ProcessException : public std::exception {
public:
    explicit ProcessException(std::string msg)
        : _msg(std::move(msg))
    {
    }

    [[nodiscard]] const char *what() const noexcept override
    {
        return _msg.c_str();
    }

private:
    std::string _msg;
};

template<typename... Args>
class Process {
public:
    explicit Process(void(*func)(std::pair<int, int> fds, Args... args_func), Args... args)
        : _pid(0),
          _fd_child_writer{0, 0},
          _fd_parent_writer{0, 0}
    {
        if (pipe(_fd_child_writer) == -1)
            throw ProcessException("Pipe creation failed");
        if (pipe(_fd_parent_writer) == -1)
            throw ProcessException("Pipe creation failed");
        _pid = fork();
        if (_pid == -1)
            throw ProcessException("Fork failed");
        if (_pid == 0) {
            close(_fd_child_writer[0]);
            _fd_child_writer[0] = -1;
            close(_fd_parent_writer[1]);
            _fd_parent_writer[1] = -1;
            std::pair<int, int> fds = {_fd_parent_writer[0], _fd_child_writer[1]};
            func(fds, args...);
            close(_fd_child_writer[1]);
            close(_fd_parent_writer[0]);
            exit(0);
        }
        close(_fd_child_writer[1]);
        _fd_child_writer[1] = -1;
        close(_fd_parent_writer[0]);
        _fd_parent_writer[0] = -1;
    }

    ~Process()
    {
        tryClose();
    }

    [[nodiscard]] int getPid() const
    {
        return _pid;
    }

    void tryWrite(const std::string &str)
    {
        if (write(_fd_parent_writer[1], str.c_str(), str.size()) == -1)
            throw ProcessException("Write failed");
    }

    std::string tryRead()
    {
        if (!checkIfCanRead(_fd_child_writer[0]))
            return "";

        char buffer[4096];
        int size;

        if ((size = read(_fd_child_writer[0], buffer, 4096)) == -1)
            throw ProcessException("Read failed");
        buffer[size] = '\0';
        return {buffer};
    }

    std::string tryRead(size_t strSize)
    {
        if (!checkIfCanRead(_fd_child_writer[0]))
            return "";

        char buffer[4096];
        int size;

        if ((size = read(_fd_child_writer[0], buffer, strSize)) == -1)
            throw ProcessException("Read failed");
        if (size < strSize)
            strSize = size;
        buffer[strSize] = '\0';
        return {buffer};
    }

    void tryClose()
    {
        if (_fd_child_writer[0] != -1) {
            if (close(_fd_child_writer[0]) == -1)
                throw ProcessException("Close failed");
            _fd_child_writer[0] = -1;
        }
        if (_fd_parent_writer[1] != -1) {
            if (close(_fd_parent_writer[1]) == -1)
                throw ProcessException("Close failed");
            _fd_parent_writer[1] = -1;
        }
    }

    void tryWait() const
    {
        int status = 0;

        if (waitpid(_pid, &status, 0) == -1)
            throw ProcessException("Waitpid failed");
    }

    void justKill()
    {
        tryClose();
        if (kill(_pid, SIGKILL) == -1)
            throw ProcessException("Kill failed");
    }

    void tryKill() const
    {
        if (_fd_child_writer[0] == -1 || _fd_child_writer[1] == -1)
            throw ProcessException("Process already closed");
        if (kill(_pid, SIGKILL) == -1)
            throw ProcessException("Kill failed");
    }

    void tryTerm() const
    {
        if (_fd_child_writer[0] == -1 || _fd_child_writer[1] == -1)
            throw ProcessException("Process already closed");
        if (kill(_pid, SIGTERM) == -1)
            throw ProcessException("Kill failed");
    }

    int getChildWriterReadFd()
    {
        return _fd_child_writer[0];
    }

    int getParentWriterWriteFd()
    {
        return _fd_parent_writer[1];
    }

private:
    pid_t _pid;
    int _fd_child_writer[2];
    int _fd_parent_writer[2];
};

#endif //PROCESS_HPP
