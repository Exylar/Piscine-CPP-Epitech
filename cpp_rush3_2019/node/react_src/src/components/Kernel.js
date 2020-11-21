import React, {Component} from 'react';
import {observer} from 'mobx-react';
import {Card, CardHeader, CardBody, CardFooter,
  Label, Container, Row, Col, Spinner} from 'reactstrap';

@observer class Kernel extends Component {
  constructor(props) {
    super(props);
    this.state = {
    };
  }

  render() {
    let data = this.props.store.data;

    return (
      <div>
        <Card>
          <CardHeader>Kernel</CardHeader>
          <CardBody>
            { this.props.store.loading ?
              <div className="loader">
                <Spinner size="lg" type="grow" />
                <Spinner size="lg" type="grow" />
                <Spinner size="lg" type="grow" />
              </div>
              :
              <div>
                <span className="key">Version: </span><span>{data.KernelVersion}</span><br></br>
                <span className="key">Uptime: </span><span>{data.Uptime}</span><br />
                <span className="key">System name: </span><span>{data.SystemName}</span><br />
              </div>
            }
          </CardBody>
        </Card>
      </div>
    )
  }
}

export default Kernel;