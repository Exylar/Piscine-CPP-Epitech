import React from 'react';
import {Card, CardHeader, CardBody, CardFooter,
        Button} from 'reactstrap';

import axios from 'axios';

class ApiTester extends React.Component {

  constructor(props) {
    super(props);
    this.state = {
      response: null,
    };
  }

  render() {
    return (
      <div>
        <Card>
          <CardHeader>API Tester</CardHeader>
          <CardBody style={{minHeight: '100px'}}>
            <p>
              {
                this.state.response ? (
                  this.state.response
              ) : (
                'Aucune Requête envoyé'
              )}
            </p>
          </CardBody>
          <CardFooter>
            <Button style={{marginRight: '15px'}} color='primary' onClick={this.testGet}>Test GET</Button>
            <Button color='primary' onClick={this.testPost}>Test POST</Button>
          </CardFooter>
        </Card>
      </div>
    )
  }

  testGet = () => {
    axios.get('/api/test')
      .then(res => {
          console.log(res.data);
          this.setState({response: JSON.stringify(res.data)})
      })
      .catch(err => {
        console.log(err)
        this.setState({response: JSON.stringify(err)});
      });
  }

  testPost = () => {
    axios.post('/api/test', {testData: 'hello world'})
      .then(res => {
          console.log(res.data);
          this.setState({response: JSON.stringify(res.data)});
      })
      .catch(err => {
        console.log(err)
        this.setState({response: err.message});
      });
  }
}

export default ApiTester;