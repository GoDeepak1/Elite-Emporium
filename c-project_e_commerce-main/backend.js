const express = require('express');
const path = require('path');

const app = express();
const port = 3000;

// Middleware to serve static files
app.use(express.static(path.join(__dirname, 'public')));

// Route to handle the cart operations
app.use('/cart', require('./routes/cart'));

// Start the server
app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});
