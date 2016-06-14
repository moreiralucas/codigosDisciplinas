program nove;
var
numero : ansistring;
cont, h , soma : longint;
function recursao (name : ansistring) : longint;
var
i, convert: longint; 
begin
        soma := 0;
        for i := 1 to length(name) do
        begin
            val(name[i], convert);
            soma += convert;    
        end;
        str(soma, name);

            if(soma <= 9)then
                if(soma = 9)then
                recursao := 1
                else
                recursao := 0
            else
                begin
                recursao(name);
                cont += 1;
                end;
end;
begin
    while not eof do
    begin
    	readln(numero);
    	soma := 0;
    	if(numero = '0')then
    		break;
    	cont := 1;
    	h := (recursao(numero));
    	if(h = 0) or (soma < 9)then
    		writeln(numero, ' is not a multiple of 9.')
    	else
    		writeln(numero, ' is a multiple of 9 and has 9-degree ', cont,'.');    
    end;
end.
