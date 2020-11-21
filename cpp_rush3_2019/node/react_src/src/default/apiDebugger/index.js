import React from 'react';
import {Card, CardHeader, CardBody, CardFooter,
        Input, Button, Container, Row, Col, Label} from 'reactstrap';
import {JsonEditor} from 'jsoneditor-react';
import 'jsoneditor-react/es/editor.min.css';

import axios from 'axios';

class ApiDebugger extends React.Component {

  constructor(props) {
    super(props);
    this.state = {
      response: null,

      method: 'POST',
      endpoint: '',
      header: {},
      body: {},
      invalid: false,
    };
  }

  render() {
    return (
      <div>
        <Card>
          <CardHeader>API Debugger</CardHeader>
          <CardBody style={{minHeight: '100px'}}>
            <Container>
              <Row>
                <Col md={3}>
                  <div style={{marginTop: '5px'}}>
                    <Input type='select' value={this.state.method} onChange={this._methodChange}>
                      <option>POST</option>
                      <option>GET</option>
                      <option>PUT</option>
                      <option>DELETE</option>
                    </Input>
                  </div>
                </Col>
                <Col md={9}>
                  <div style={{marginTop: '5px'}}>
                    <Container>
                      <Row>
                        <Col>
                          <p style={{lineHeight: '40px', textAlign: 'right'}}>{window.env.backUrl}</p>
                        </Col>
                        <Col>
                          <Input type='text' placeholder='Endpoint...' value={this.state.endpoint} onChange={this._endpointChange} />
                        </Col>
                      </Row>
                    </Container>
                  </div>
                </Col>
              </Row>
              <Row>
                <Col>
                  <Label>Header</Label>
                  <JsonEditor value={this.state.header} onChange={this._headerChange} />
                </Col>
              </Row>
              <div style={{height: '10px'}}></div>
              { this.state.method !== 'GET' &&
                <Row>
                  <Col>
                    <Label>Body: </Label>
                    <JsonEditor value={this.state.body} onChange={this._bodyChange} />
                  </Col>
                </Row>
              }
              <div style={{height: '10px'}}></div>
              <Card>
                <CardBody>

                <p>
                  {
                    this.state.response ? (
                      this.state.response
                      ) : (
                        'Aucune Requête envoyé'
                        )}
                </p>
                { this.state.invalid &&
                  <p style={{color: 'red'}}>{this.state.invalid}</p>
                }
                </CardBody>

              </Card>
            </Container>

          </CardBody>
          <CardFooter>
            <Button color='primary' onClick={this._call}>Call</Button>
          </CardFooter>
        </Card>
      </div>
    )
  }

  // -------------------------- actions --------------------------- //
  _call = () => {
    let axiosParam;
    
    this.setState({invalid: false});
    axiosParam = {
      headers: this.state.header,
      url: this.state.endpoint,
      method: this.state.method,
    };
    if (this.state.method !== 'GET')
      axiosParam.data = this.state.body;
    this.doCall(axiosParam);
  }
  // -------------------------- method --------------------------- //
  /**
   * do call api and set response in state
   * @param {JSON} content with axios format
   * @return {JSON} response
   */
  doCall(content) {
    axios.request(content)
      .then(res => this.setState({response: JSON.stringify(res.data)}))
      .catch(err => this.setState({invalid: err.message}));
  }
  // -------------------------- champs controllés --------------------------- //
  _methodChange = (e) => {
    this.setState({method: e.target.value});
  }
  _endpointChange = (e) => {
    this.setState({endpoint: e.target.value});
  }
  _headerChange = (e) => {
    this.setState({header: e});
  }
  _bodyChange = (e) => {
    this.setState({body: e});
  }
}

export default ApiDebugger;