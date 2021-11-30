const PIN = "1234";
var budget = 1400;

function Verify() {
    if (prompt('Enter your PIN') == PIN) {
        alert('Welcome user');
    } else {
        alert('Access denied');
        window.close();
    }
}

function checkBalance() {
    //haven't really practiced javascript so I used a variable for budget
    alert("Your budget: $" + budget);
}

function Withdraw(amount) {
    if(0 < amount && amount<=budget) {
        budget -= amount;
        alert('Withdrawal made successfully!');
    } else {
        alert('You must enter a number between 0 and your budget')
    }
}

function Deposit(amount) {
    budget+=amount;
    alert("Deposit made successfully");
}