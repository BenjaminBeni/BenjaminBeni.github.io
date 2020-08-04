function ready() {
    var body = document.getElementsByTagName('body')[0]
    for(var i = 1; i <= 116; i++){
        var name = "pic" + JSON.stringify(i)
        var responsive = document.createElement("div")
        responsive.className = "responsive"
        var gallery = document.createElement("div")
        gallery.className = "gallery"
        var image = document.createElement("img")
        image.src = "./photos/" + name + ".jpg"
        image.width = "600"
        image.height = "400"

        gallery.append(image)
        responsive.append(gallery)

        body.append(responsive)
    }
    var clrfix = document.createElement("div")
    clrfix.className = "clearfix"
    body.append(clrfix)
}

