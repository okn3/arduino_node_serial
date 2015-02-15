var serialport = require('serialport');

// Serial Port
var portName = '/dev/tty.usbmodem1421'; // Mac環境
var sp = new serialport.SerialPort(portName, {
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false,
    parser: serialport.parsers.readline("\n")   // ※修正：パースの単位を改行で行う
});

// data from Serial port
sp.on('data', function(input) {

    var buffer = new Buffer(input, 'utf8');
    var jsonData;
    try {
        jsonData = JSON.parse(buffer);
        console.log('no: '+jsonData.no ); 
        console.log('temp: ' + jsonData.temp);
        console.log('bright: ' + jsonData.bright);
        console.log('---------------------');
    } catch(e) {
        // データ受信がおかしい場合無視する
        return;
    }
    // つながっているクライアント全員に送信
    //io.sockets.json.emit('message', { value: jsonData });
});

