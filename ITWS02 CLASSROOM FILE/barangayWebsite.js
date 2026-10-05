const officials = [

    {
        name: "Rustico C. San Diego",

        position: "Punong Barangay",

        description:
            "Responsible for overseeing barangay governance, public services, and community programs.",

        contact: "0995-151-0646",

        image: ""
    },


    {
        name: "Edna B. Dela Cruz",

        position: "BNS/BHERT Member",

        description:
            "Responsible for barangay records, documentation, and administrative support.",

        contact: "0975-709-0995",

        image: ""
    },


    {
        name: "Nonito C Guiao",

        position: "Barangay Kagawad",

        description:
            "Responsible for Assists in implementing barangay programs, addressing community concerns, and enforcing local ordinances.",


        contact: "0965-688-8628",

        image: ""
    },

    {
        name: "Aeymhard Escultura",

        position: "Chief Tanod",

        description: "Responsible for leading barangay tanonds in maintaining peace, order, and community safety.",

        contact: "0967-849-4910",

        image: ""
    }

];

    

/* =========================================
   DISPLAY OFFICIALS
========================================= */

function displayOfficials(list = officials) {

    const container =
        document.getElementById("officialsContainer");


    container.innerHTML = "";


    if (list.length === 0) {

        container.innerHTML = `

            <p style="
                grid-column: 1 / -1;
                text-align: center;
            ">

                No officials found.

            </p>

        `;

        return;
    }


    list.forEach(function(official) {


        let image;


        if (official.image !== "") {

            image = official.image;

        } else {

            image =
                "https://via.placeholder.com/600x500?text=Official+Photo";

        }


        container.innerHTML += `

            <div class="official-card">

                <img
                    class="official-image"
                    src="${image}"
                    alt="${official.name}"
                >


                <div class="official-info">

                    <span class="position">
                        ${official.position}
                    </span>


                    <h3>
                        ${official.name}
                    </h3>


                    <p class="official-description">
                        ${official.description}
                    </p>


                    <div class="official-contact">

                        <p>
                            📞
                            ${official.contact || "Not provided"}
                        </p>

                        <p>
                            ✉️
                            ${official.email || "Not provided"}
                        </p>

                    </div>

                </div>

            </div>

        `;

    });

}


/* =========================================
   SEARCH OFFICIALS
========================================= */

function searchOfficials() {

    const search =
        document
            .getElementById("searchInput")
            .value
            .toLowerCase();


    const results =
        officials.filter(function(official) {

            return (

                official.name
                    .toLowerCase()
                    .includes(search)

                ||

                official.position
                    .toLowerCase()
                    .includes(search)

            );

        });


    displayOfficials(results);

}


/* =========================================
   CURRENT YEAR
========================================= */

document.getElementById("year").textContent =
    new Date().getFullYear();


/* =========================================
   INITIAL WEBSITE LOAD
========================================= */

displayOfficials();


/* =========================================
   NATIONAL HOTLINES POPUP
========================================= */

function openHotlines() {
    document.getElementById("tble").style.display = "block";
}

function closeHotlines() {
    document.getElementById("tble").style.display = "none";
}

// Close hotline popup when clicking outside the table

document.addEventListener("click", function(event) {

    const hotline = document.getElementById("tble");

    if (event.target === hotline) {

        closeHotlines();

    }

});


/* =========================================
   CONCERN FORM

   Setup: create a free form at formspree.io,
   then replace YOUR_FORM_ID below with the ID
   they give you. Submissions will be emailed
   to you.
========================================= */

const CONCERN_FORM_ENDPOINT =
    "https://formspree.io/f/YOUR_FORM_ID";

const concernForm =
    document.getElementById("concernForm");

const concernMessage =
    document.getElementById("concernMessage");

const messageCount =
    document.getElementById("messageCount");

const formStatus =
    document.getElementById("formStatus");

const submitConcern =
    document.getElementById("submitConcern");


/* Live character counter */

concernMessage.addEventListener("input", function() {

    messageCount.textContent =
        concernMessage.value.length + " / 1000";

});


/* Show or clear an error under a field */

function setFieldError(fieldId, message) {

    const group =
        document.getElementById(fieldId)
            .closest(".form-group");

    const error =
        group.querySelector(".form-error");

    if (message) {

        group.classList.add("invalid");

        error.textContent = message;

    } else {

        group.classList.remove("invalid");

        error.textContent = "";

    }

}


/* Show a success or error box under the button */

function showStatus(type, message) {

    formStatus.className = "form-status " + type;

    formStatus.textContent = message;

}


function hideStatus() {

    formStatus.className = "form-status";

    formStatus.textContent = "";

}


/* Validate every field before sending */

function validateConcernForm() {

    let valid = true;


    const name =
        document.getElementById("concernName").value.trim();

    const phone =
        document.getElementById("concernPhone").value.trim();

    const email =
        document.getElementById("concernEmail").value.trim();

    const category =
        document.getElementById("concernCategory").value;

    const message =
        concernMessage.value.trim();

    const consent =
        document.getElementById("concernConsent").checked;


    if (name.length < 2) {

        setFieldError(
            "concernName",
            "Please enter your full name."
        );

        valid = false;

    } else {

        setFieldError("concernName", "");

    }


    if (phone !== "" && !/^[0-9+\-\s()]{7,20}$/.test(phone)) {

        setFieldError(
            "concernPhone",
            "Please enter a valid contact number."
        );

        valid = false;

    } else {

        setFieldError("concernPhone", "");

    }


    if (email !== "" && !/^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(email)) {

        setFieldError(
            "concernEmail",
            "Please enter a valid email address."
        );

        valid = false;

    } else {

        setFieldError("concernEmail", "");

    }


    if (category === "") {

        setFieldError(
            "concernCategory",
            "Please choose a category."
        );

        valid = false;

    } else {

        setFieldError("concernCategory", "");

    }


    if (message.length < 10) {

        setFieldError(
            "concernMessage",
            "Please write at least 10 characters."
        );

        valid = false;

    } else {

        setFieldError("concernMessage", "");

    }


    if (!consent) {

        setFieldError(
            "concernConsent",
            "Please agree before submitting."
        );

        valid = false;

    } else {

        setFieldError("concernConsent", "");

    }


    return valid;

}


/* Submit */

concernForm.addEventListener("submit", async function(event) {

    event.preventDefault();

    hideStatus();


    if (!validateConcernForm()) {

        return;

    }


    /* Spam trap: bots fill this hidden field */

    if (document.getElementById("concernWebsite").value !== "") {

        return;

    }


    if (CONCERN_FORM_ENDPOINT.includes("YOUR_FORM_ID")) {

        showStatus(
            "error",
            "This form is not connected yet. Please add your form service ID in barangayWebsite.js."
        );

        return;

    }


    submitConcern.disabled = true;

    submitConcern.textContent = "Sending...";


    try {

        const response = await fetch(CONCERN_FORM_ENDPOINT, {

            method: "POST",

            headers: {
                "Accept": "application/json"
            },

            body: new FormData(concernForm)

        });


        if (response.ok) {

            showStatus(
                "success",
                "Thank you! Your concern has been sent to the barangay."
            );

            concernForm.reset();

            messageCount.textContent = "0 / 1000";

        } else {

            showStatus(
                "error",
                "Something went wrong. Please try again or visit the barangay hall."
            );

        }

    } catch (error) {

        showStatus(
            "error",
            "Could not send. Please check your internet connection and try again."
        );

    }


    submitConcern.disabled = false;

    submitConcern.textContent = "Submit Concern";

});