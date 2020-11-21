import React, {Component} from 'react';
import {observer} from 'mobx-react';
import {Card, CardHeader, CardBody, CardFooter,
  Label, Container, Row, Col, Spinner} from 'reactstrap';


@observer class Network extends Component {
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
          <CardHeader>Network</CardHeader>
          <CardBody>
          { this.props.store.loading ?
              <div className="loader">
                <Spinner size="lg" type="grow" />
                <Spinner size="lg" type="grow" />
                <Spinner size="lg" type="grow" />
              </div>
              :
              <div>
                <span className="key">in:</span><span>{data.Download}</span><br></br>
                <span className="key">out</span><span>{data.Upload}</span><br></br>
              </div>
            }
          </CardBody>
        </Card>
      </div>
    )
  }
}

export default Network;