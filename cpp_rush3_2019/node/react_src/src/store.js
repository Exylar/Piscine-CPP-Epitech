import {observable, action } from 'mobx';
import axios from 'axios';

class MonitorStore {
  @action pull() {
    axios.get('http://localhost:4000/api/test')
      .then(r => {
        this.data = r.data;
        this.loading = false;
      })
  }

  @observable data = {}
  @observable loading = true;
}

export default MonitorStore;