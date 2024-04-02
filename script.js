async function runProcess(name = '') {
    try {
        const response = await fetch(`https://freetestapi.com/api/v1/countries?search=${name}&sort=name&order=dec`);
        const json = await response.json();
        const first20Countries = json.slice(0, 20);
        setData(first20Countries);
    } catch (error) {
        console.log(error);
    }
}
runProcess()
const setData = (json) => {
    const product = document.querySelector('.product')
    console.log(json)
    product.innerHTML = ''
    json.forEach(ele => {
        const div = document.createElement('div')
        div.innerHTML = `
            <img src=${ele.flag} alt="image of proucts" />
            <h4>${ele.name}</h4>
            <div class="Country">
                <p>Population : ${ele.population}</p>
                <p>Density : ${ele.density}</p>
                <p>Capital : ${ele.capital}</p>
                <p>Land_Area : ${ele.land_area}</p>
            </div>
        `
        product.appendChild(div)
    });
}

setData()

function handleInput() {
    let inputElement = document.getElementById("userInput");
    let userInputValue = inputElement.value;
    runProcess(userInputValue);
}
