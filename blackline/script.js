// Show and hide the menu on smaller screens
const menuBtn = document.getElementById("menuBtn");
const navMenu = document.getElementById("navMenu");

menuBtn.addEventListener("click", function () {
    navMenu.classList.toggle("show");
});

// Close the menu after clicking a link
const navLinks = navMenu.querySelectorAll("a");

navLinks.forEach(function (link) {
    link.addEventListener("click", function () {
        navMenu.classList.remove("show");
    });
});

// Set today's date as the earliest booking date
const dateField = document.getElementById("date");
const today = new Date();
const dateText = today.getFullYear() + "-" +
    String(today.getMonth() + 1).padStart(2, "0") + "-" +
    String(today.getDate()).padStart(2, "0");

dateField.min = dateText;

// Haircut style table: fill the style list and let customers pick a style
const styleRows = document.querySelectorAll(".style-table tbody tr");
const styleField = document.getElementById("styleChoice");
const serviceField = document.getElementById("serviceChoice");

function markStyle(name) {
    styleRows.forEach(function (row) {
        const picked = row.dataset.style === name;
        row.classList.toggle("selected", picked);
        row.querySelector(".pick-btn").textContent = picked ? "CHOSEN ✓" : "CHOOSE ↗";
    });
}

styleRows.forEach(function (row) {
    const option = document.createElement("option");
    option.textContent = row.dataset.style;
    styleField.appendChild(option);

    // Find the matching service (and its price) from the booking form
    const service = Array.from(serviceField.options).find(function (o) {
        return o.value.startsWith(row.dataset.service);
    });
    if (service) {
        row.querySelector(".service-cell").textContent = service.value;
    }

    row.querySelector(".pick-btn").addEventListener("click", function () {
        styleField.value = row.dataset.style;
        if (service) {
            serviceField.value = service.value;
        }
        markStyle(row.dataset.style);
        document.getElementById("booking").scrollIntoView();
    });
});

styleField.addEventListener("change", function () {
    markStyle(styleField.value);
});

// Show a message when the booking form is submitted
const bookingForm = document.getElementById("bookingForm");
const message = document.getElementById("message");

bookingForm.addEventListener("submit", function (event) {
    event.preventDefault();

    const customerName = document.getElementById("name").value;
    const chosenService = document.getElementById("serviceChoice").value;
    const chosenDate = dateField.value;
    const chosenTime = document.getElementById("time").value;
    const chosenStyle = styleField.value;

    message.textContent = "Thank you, " + customerName +
        "! Your request for " + chosenService +
        (chosenStyle ? " (" + chosenStyle + " style)" : "") +
        " on " + chosenDate + " at " + chosenTime +
        " has been received. Please contact the shop to confirm.";

    bookingForm.reset();
    markStyle("");
    dateField.min = dateText;
});
