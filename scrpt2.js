document.addEventListener("DOMContentLoaded", function () {
    fetchData();
});

async function fetchData() {
    try {
        const response = await fetch('https://restcountries.com/v3.1/all');
        const data = await response.json();
        displayData(data);
    } catch (error) {
        console.log(error);
    }
}

function displayData(data) {
    const countryList = document.getElementById('countryList');
    countryList.innerHTML = '';

    data.forEach(country => {
        const countryElement = document.createElement('div');
        countryElement.classList.add('country');
        countryElement.innerHTML = `
      <h2>${country.name.common}</h2>
      <p>Capital: ${country.capital ? country.capital[0] : 'N/A'}</p>
      <p>Region: ${country.region ? country.region : 'N/A'}</p>
      <p>Population: ${country.population ? country.population.toLocaleString() : 'N/A'}</p>
      <p>Area: ${country.area ? country.area.toLocaleString() : 'N/A'} km<sup>2</sup></p>
    `;
        countryList.appendChild(countryElement);
    });
}

function sortCountries() {
    const countryElements = Array.from(document.querySelectorAll('.country'));
    const sortedCountries = countryElements.sort((a, b) => {
        const nameA = a.querySelector('h2').textContent.toUpperCase();
        const nameB = b.querySelector('h2').textContent.toUpperCase();
        if (nameA < nameB) {
            return -1;
        }
        if (nameA > nameB) {
            return 1;
        }
        return 0;
    });

    const countryList = document.getElementById('countryList');
    countryList.innerHTML = '';
    sortedCountries.forEach(country => {
        countryList.appendChild(country);
    });
}

document.getElementById('searchInput').addEventListener('input', function () {
    const searchTerm = this.value.toLowerCase();
    const countryElements = Array.from(document.querySelectorAll('.country'));
    countryElements.forEach(country => {
        const countryName = country.querySelector('h2').textContent.toLowerCase();
        if (countryName.includes(searchTerm)) {
            country.style.display = 'block';
        } else {
            country.style.display = 'none';
        }
    });
});
