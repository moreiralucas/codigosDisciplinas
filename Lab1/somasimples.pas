program somasimples;

var
	m1: real;
	m2: real;
	m3: real;
	m4: real;
	mt: real;
	mf: real;
begin
	write ('escreva a m1 ') ;
	read (m1) ;
	write ('escreva a m2 ') ;
	read (m2) ;
	write ('escreva m3 ') ;
	read (m3) ;
	write ('escreva m4 ') ;
	read (m4) ;
	mt:= m1+m2+m3+m4 ;
	write ('media final ') ;
	write (mt/4 :0:2) ;
	mf:=mt/4;
	
	if mf < 7.0 then 
		writeln (' está reprovado ') 
	else 
		writeln (' está aprovado') ;


end.
