import React, {Component} from 'react';
import {observer} from 'mobx-react';
import {Card, CardHeader, CardBody, CardFooter,
  Label, Container, Row, Col, Spinner} from 'reactstrap';


@observer class Time extends Component {
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
          <CardHeader>Time</CardHeader>
          <CardBody>
          { this.props.store.loading ?
              <div className="loader">
                <Spinner size="lg" type="grow" />
                <Spinner size="lg" type="grow" />
                <Spinner size="lg" type="grow" />
              </div>
              :
              <div>
                <span className="key">Date</span><span>{data.Date}</span><br></br>
                <span className="key">Time</span><span>{data.Heure}</span>

              </div>
            }
          </CardBody>
        </Card>
      </div>
    )
  }
}

export default Time;