var
	a,b,x,tmp,i,cn,an: longint;
begin
	read(a,b);
	tmp:=a-b;
	if a=b then writeln('infinity')
	else if a<b then writeln(0)
	 else
	 begin
	   if b+1>=(tmp div 2) then begin for i:=b+1 to tmp do if tmp mod i=0 then cn:=cn+1; end
	   else 
	     begin
	     	for i:=1 to trunc(sqrt(tmp)) do if tmp mod i=0 then cn:=cn+2;
	     	for i:=1 to b do if tmp mod i=0 then an:=an+1;
	     	if sqr(trunc(sqrt(tmp)))=tmp then cn:=cn-1;
	     	cn:=cn-an;
	     end;
	   writeln(cn);
	 end;
end.