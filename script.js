function showTime(){
    var date = new Date();
    var hrs = date.getHours(); // 0 - 23
    var min = date.getMinutes(); // 0 - 59
    var sec = date.getSeconds(); // 0 - 59
    var session = document.getElementById('session');
    
    if(hrs>=12){
        session.innerHTML = 'PM';
    }
    else{
        session.innerHTML = 'AM';
    }

    if(hrs>12){
        hrs = hrs - 12;
    }

    document.getElementById('hours').innerHTML = hrs;
    document.getElementById('minutes').innerHTML = min;
    document.getElementById('seconds').innerHTML = sec;
}

setInterval(showTime,1000);