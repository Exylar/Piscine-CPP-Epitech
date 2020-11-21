import React from 'react';
import MonitorStore from './store';
import {Container, Row, Col, Jumbotron} from 'reactstrap';

import Kernel from './components/Kernel';
import Cpu from './components/Cpu';
import Network from './components/Network';
import Ram from './components/Ram';
import Time from './components/Time';
import UserHost from './components/UserHost';

class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
    };

    this.store = new MonitorStore();
    this.store.loading = true;
    this.loop();
    window.setInterval(this.loop, 5000);


  }
  loop = () => {
    this.store.pull();
  }
  render() {
    return (
      <div style={{padding: "100px"}}>
        <Jumbotron><h1>Tek Monitor</h1></Jumbotron>
        <Container fluid>
          <Row>
            <Col lg={4}>
              <Kernel store={this.store} />
            </Col>
            <Col lg={4}>
              <UserHost store={this.store} />
            </Col>
            <Col lg={4}>
              <Time store={this.store} />
            </Col>
            <Col lg={4}>
              <Cpu store={this.store} />
            </Col>
            <Col lg={3}>
              <Network store={this.store} />
            </Col>
            <Col lg={5}>
              <Ram store={this.store} />
            </Col>
          </Row>
        </Container>
      </div>
    )
  }
}

export default App;