import React, {Component} from 'react';
import {observer} from 'mobx-react';
import {Card, CardHeader, CardBody, CardFooter, Progress,
  Label, Container, Row, Col, Spinner} from 'reactstrap';


@observer class Ram extends Component {
  constructor(props) {
    super(props);
    this.state = {
    };
  }

  render() {
    let data = this.props.store.data;

    let memTotal = parseInt(data['mem total']);
    let memFree = parseInt(data['mem free']);
    let swapTotal = parseInt(data['swap total']);
    let swapFree = parseInt(data['swrap free']);
    return (
      <div>
        <Card>
          <CardHeader>Ram</CardHeader>
          <CardBody>
          { this.props.store.loading ?
            <div className="loader">
              <Spinner size="lg" type="grow" />
              <Spinner size="lg" type="grow" />
              <Spinner size="lg" type="grow" />
            </div>
            :
            <div style={{width: '100%'}}>

              <Container fluid>
                <Row>
                  <Col md={2}><span className="key">RAM: </span></Col>
                  <Col md={10}>
                    <Progress animated value={memTotal - memFree} max={memTotal} />
                  </Col>
                </Row>
                <Row>
                  <Col md={2}><span className="key">SWAP: </span></Col>
                  <Col md={10}>
                    <Progress animated value={swapTotal - swapFree} max={swapTotal} />
                  </Col>
                </Row>
              </Container>
            </div>
          } 
          </CardBody>
        </Card>
      </div>
    )
  }
}

export default Ram;