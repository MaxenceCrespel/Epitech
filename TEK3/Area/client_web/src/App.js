import React from 'react';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';
import { AuthProvider } from './AuthContext';
import { ColorProvider } from './components/ColorContext';
import PrivateRoute from './PrivateRoutes';
import Dashboard from './pages/Dashboard';
import LoginForm from './pages/LoginForm';
import Settings from './pages/Settings';
import RegistrationForm from './pages/RegistrationForm';
import Action from './pages/Action';
import Reaction from './pages/Reaction';
import Applet from './pages/Applet'

function App() {
  return (
    <AuthProvider>
      <ColorProvider> {
        <Router>
          <Switch>
            <Route path="/" exact component={LoginForm} />
            <Route path="/LoginForm" exact component={LoginForm} />
            <Route path="/RegistrationForm" component={RegistrationForm} />
            <Route path="/Dashboard" component={Dashboard} />
            <PrivateRoute path="/Settings" component={Settings} />
            <PrivateRoute path="/Action" component={Action} />
            <PrivateRoute path="/Reaction" component={Reaction} />
            <PrivateRoute path="/Applet" component={Applet} />
          </Switch>
        </Router>
      }
      </ColorProvider>
    </AuthProvider>
  );
}

export default App;
