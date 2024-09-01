const express = require('express');
const router = express.Router();

// Example route to get cart items
router.get('/', (req, res) => {
    res.json({ message: 'Cart operations can be handled here.' });
});

module.exports = router;
