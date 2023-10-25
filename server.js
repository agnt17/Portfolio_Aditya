const express = require('express');
const bodyParser = require('body-parser');
const nodemailer = require('nodemailer');
const app = express();

// Middleware to parse form data
app.use(bodyParser.urlencoded({ extended: true }));

// Serve static files (CSS, images, etc.) if needed
app.use(express.static('public'));

// Serve your HTML form
app.get('/', (req, res) => {
  res.sendFile("index.html");
});

// Handle form submissions
app.post('/submit', (req, res) => {
  const { name, email, subject, message } = req.body;

  // Configure your email transport (e.g., using nodemailer)
  const transporter = nodemailer.createTransport({
    service: 'Gmail', // e.g., 'Gmail', 'SendGrid'
    auth: {
      user: 'adityagupta20042003@gmail.com',
      pass: 'Asdf4321@#',
    },
  });

  // Email content
  const mailOptions = {
    from: email,
    to: 'adityagupta20042003@gmail.com',
    subject: subject,
    text: message,
  };

  // Send the email
  transporter.sendMail(mailOptions, (error, info) => {
    if (error) {
      console.log(error);
      res.send('Error: Something went wrong.');
    } else {
      console.log('Email sent: ' + info.response);
      res.send('Thank you! Your message has been sent.');
    }
  });
});

// Start the server
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
