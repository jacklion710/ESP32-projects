const express = require('express');
const bodyParser = require('body-parser');
const axios = require('axios');

const app = express();
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static('public'));

app.post('/send-message', (req, res) => {
  const message = req.body.message;
  axios.get(`http://${req.body.ipAddress}/message?message=${message}`)
    .then(() => {
      res.send('Message sent successfully');
    })
    .catch((error) => {
      console.error('Error sending message:', error);
      res.status(500).send('Error sending message');
    });
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});