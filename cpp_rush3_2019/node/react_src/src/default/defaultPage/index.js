import React from 'react';
import {Button, Container, Row, Col,
  Card, CardBody, CardHeader, CardFooter} from 'reactstrap';

import ApiTester from '../apiTester';
import ApiDebugger from '../apiDebugger';
import logo from './logo.svg';

class DefaultPage extends React.Component {

  constructor(props) {
    super(props);
    this.state = {
    }
  }

  render() {
    return (
      <div style={{width: '80%', margin: 'auto'}}>
        <img src={logo} style={{display: 'block', width: '50%', margin: 'auto'}} />
        <ApiDebugger />
        <br />
        <ApiTester />
        <br />
        <p style={{textAlign: 'center'}}>Don't forget to set the .env file (in back) and the env.js file (in front). Don't push theses files</p>
      </div>
    )
  }
}

export default DefaultPage;