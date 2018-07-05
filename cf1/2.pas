var
	n,i,j,cn: Integer;
	a:array[1..100]of string;
	tmp:string;
begin
	readln(n);
	for i:=1 to n do readln(a[i]);
	for i:=1 to n-1 do
	  for j:=1 to n-i do
	    if length(a[j])>length(a[j+1]) then begin tmp:=a[j];a[j]:=a[j+1];a[j+1]:=tmp;end;
	for i:=1 to n-1 do
	  begin
	  	j:=pos(a[i],a[i+1]);
	  	if j=0 then begin cn:=1;break;end;
	  end;
	if cn=1 then writeln('NO')
	 else begin
	 	writeln('YES');
	 	for i:=1 to n do writeln(a[i]);
	 end;
end.