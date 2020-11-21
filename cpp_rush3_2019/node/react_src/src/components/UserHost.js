import React, {Component} from 'react';
import {observer} from 'mobx-react';
import {Card, CardHeader, CardBody, CardFooter,
  Label, Container, Row, Col, Spinner} from 'reactstrap';

@observer class UserHost extends Component {
  constructor(props) {
    super(props);
    this.state = {
    };
  }

  render() {
    let data = this.props.store.data;
    console.log(data);
    return (
      <div>
        <Card>
          <CardHeader>UserHost</CardHeader>
          <CardBody>
          { this.props.store.loading ?
              <div className="loader">
                <Spinner size="lg" type="grow" />
                <Spinner size="lg" type="grow" />
                <Spinner size="lg" type="grow" />
              </div>
              :
              <div>
                <span className="key">User host: </span><span>{data.Hostname}</span><br />
                <span className="key">User name: </span><span>{data.Username}</span>
              </div>
            }
          </CardBody>
        </Card>
      </div>
    )
  }
}

export default UserHost;