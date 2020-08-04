/*function ready() {
    var row = document.getElementsByClassName('row')[0]
    var counter = 1
    var col = document.createElement("div")
    col.className = "column"
    for(var i = 1; i <= 116; i++){
        var name = "pic" + JSON.stringify(i) + '.jpg'
        if (counter == 7){
            row.append(col)
            col = document.createElement("div")
            col.className = "column"
            counter = 1
        }

        var image = document.createElement("img")
        image.src = "./photos/" + name
        image.style.width = "100%"
        col.append(image)
        counter += 1
    }
}*/

function ready() {
   var photos = document.getElementById("photos")
    for(var i = 1; i <= 116; i++){
        var name = "pic" + JSON.stringify(i) + '.jpg'
        var image = document.createElement("img")
        image.src = "./photos/" + name
        image.style.width = "100%"
        photos.append(image)
    }
}
