 function genCodeStr(){
    var codeRE = new RegExp("'(.*)' : '(.*)'","gi");
    var tempStr,codeStr = "";
    var myReader = new Reader();
    myReader.loadFile('inc/gb2312_utf.txt');//这里改成你的对照表存放的路径
    while(!myReader.fStream.atEndofLine) {
        tempStr = new String(myReader.fStream.readLine());
        codeStr += tempStr.replace(codeRE,"$1") + ":" + tempStr.replace(codeRE,"$2") + ":";
    }
    Application("codeData") = codeStr;
}
function getCodeStr(){
    var codeStr = new String(Application("codeData"));
    if(codeStr.indexOf("%a1%a1") == -1){
        genCodeStr();
    }
    return new String(Application("codeData"));
}
function gb2utf(gbStr){
    var codeStr = getCodeStr();
    var codeRE = new RegExp("(%..%..)","gi");
    var replaceRE = new RegExp("(%..%..)","i");
    var gbCode;
    var utfCode;
    var gbStart;
    while((codeRE.lastIndex < gbStr.length) && replaceRE.test(gbStr)){
        codeRE.exec(gbStr);
        gbCode = new String(RegExp.$1);
        gbStart = new Number(codeStr.indexOf(gbCode.toLowerCase()));
        var utfStart = 0;
        if(gbStart != -1){
            utfStart= gbStart + 7;
            utfCode = codeStr.substring(utfStart,utfStart + 6);
        }else{
            utfCode = "%u3000";
        }
        gbStr = gbStr.replace(replaceRE,utfCode);
    }
    return gbStr;
}

function Reader() {                        //Class        Reader()
    this.fso;                            //Private    fso
    this.fUri;                            //Private    fUri
    this.fStream;                        //Private    fStream
    try{
        this.fso = new ActiveXObject("Scripting.FileSystemObject");
    }catch(exception) {
        throw exception;
    }
    this.loadFile = function(file) {        //Public        loadFile(file)
            this.fUri = Server.mappath(file);
            //var fStream = fso.CreateTextFile(tfolder,true,false);
            //fStream.WriteLine('test');
            if(this.fso.fileExists(this.fUri)){
                this.fStream = this.fso.openTextFile(this.fUri);
            }else{
                Response.write('file dos not exist');
            }
    }
    this.readLineN = function(num) {
        var i = 1;
        while(i < num && !this.fStream.atEndOfLine) {
            this.fStream.skipLine();
            i++
        }
        return this.fStream.readLine();
    }
    this.closeFile = function() {
        fStream.Close();
        fso.Close;
    }
}