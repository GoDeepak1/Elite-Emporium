// Mock product data
const products = [
    { id: 1, name: 'Dell XPS 13', price: 999.99 },
    { id: 2, name: 'Macbook Pro', price: 1299.99 },
    { id: 3, name: 'HP Spectre x360', price: 1099.99 },
    { id: 4, name: 'Lenovo ThinkPad', price: 1001.99 },
    { id: 5, name: 'Asus ZenBook', price: 899.99 },
    { id: 6, name: 'Samsung Galaxy S21', price: 859.99 },
    { id: 7, name: 'iPhone 12', price: 909.99 },
    { id: 8, name: 'Sony Bravia TV', price: 939.99 },
    { id: 9, name: 'Bose QuietComfort 35', price: 959.99 }
];

const cart = [];

function renderProducts() {
    const productList = document.getElementById('product-list');
    productList.innerHTML = '';
    products.forEach(product => {
        const productDiv = document.createElement('div');
        productDiv.className = 'product';
        productDiv.innerHTML = `
            <h3>${product.name}</h3>
            <p>Price: $${product.price}</p>
            <button onclick="addToCart(${product.id})">Add to Cart</button>
        `;
        productList.appendChild(productDiv);
    });
}

function addToCart(productId) {
    const product = products.find(p => p.id === productId);
    const cartItem = cart.find(item => item.id === productId);

    if (cartItem) {
        cartItem.quantity += 1;
    } else {
        cart.push({ ...product, quantity: 1 });
    }

    renderCart();
}

function renderCart() {
    const cartList = document.getElementById('cart-list');
    cartList.innerHTML = '';
    let total = 0;
    
    cart.forEach(item => {
        total += item.price * item.quantity;
        const cartItemDiv = document.createElement('div');
        cartItemDiv.className = 'cart-item';
        cartItemDiv.innerHTML = `
            <h3>${item.name}</h3>
            <p>Quantity: ${item.quantity}</p>
            <p>Price: $${(item.price * item.quantity).toFixed(2)}</p>
            <button onclick="removeFromCart(${item.id})">Remove</button>
        `;
        cartList.appendChild(cartItemDiv);
    });

    document.getElementById('total').textContent = total.toFixed(2);
}

function removeFromCart(productId) {
    const cartItemIndex = cart.findIndex(item => item.id === productId);
    if (cartItemIndex !== -1) {
        cart.splice(cartItemIndex, 1);
    }
    renderCart();
}

document.getElementById('checkout-btn').addEventListener('click', () => {
    if (cart.length > 0) {
        alert('Thank you for your purchase!');
        cart.length = 0; // Clear cart
        renderCart();
    } else {
        alert('Your cart is empty!');
    }
});

// Initial render
renderProducts();
