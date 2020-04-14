function f(){

    var str = prompt("Enter a string made of alphabetical letters only");

    document.getElementById("str").innerText += " " + str;

    var obj = {};

    for(var i = 0; i < str.length; i++){
        if(obj[str[i]]){
            obj[str[i]]++;
        }
        else{
            obj[str[i]] = 1;
        }
    }

    var arr = Object.keys(obj);
    
    var len = 0;

    var ok = 1;

    for(var i = 0; i < arr.length; i++){
        if(obj[arr[i]] % 2 == 0){
            len = len + obj[arr[i]];
        }
        else{
            if(ok == 1){
                len = len + obj[arr[i]];
                ok = 0;
            }
            else{
                len = len + obj[arr[i]] - 1;
            }
        }
    }

    document.getElementById("lng").innerText += " " + len;

}