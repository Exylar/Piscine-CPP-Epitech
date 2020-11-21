import React, {Component} from 'react';
import {observer} from 'mobx-react';
import {Card, CardHeader, CardBody, CardFooter, Progress,
        Label, Container, Row, Col, Spinner} from 'reactstrap';

@observer class Cpu extends Component {
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
          <CardHeader>Cpu</CardHeader>
          <CardBody>
          { this.props.store.loading ?
              <div className="loader">
                <Spinner size="lg" type="grow" />
                <Spinner size="lg" type="grow" />
                <Spinner size="lg" type="grow" />
              </div>
              :
              <div>
                <span className="key">Model: </span><span>{data.Model}</span><br></br>
                <span className="key">Core: </span><span>{data.NbCore}</span><br></br>
                <span className="key">Frequency: </span><span>{data.Frequency}MHz</span><br></br>
                <span className="key">Activity: </span> {data.Activity}
                <Progress animated value={data.Activity.split('%')[0]}/>
              </div>
            }
          </CardBody>
        </Card>
      </div>
    )
  }
}

export default Cpu;