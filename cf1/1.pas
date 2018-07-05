var
 n,k,i,j,tmp,cn:longint;
 a,b,c:array[1..100] of longint;
begin
	read(n,k);
	for i:=1 to n do begin read(tmp); a[tmp]:=a[tmp]+1;b[i]:=tmp;end;
	for i:=1 to 100 do 
	 begin
	 	if a[i]>0 then begin cn:=cn+1;end;
	 end;
	if cn<k then writeln('NO')
	 else
	  begin
	  	writeln('YES');
	  	for i:=1 to k do 
	  	 for j:=1 to n do
	  	  if (b[j]>0)and(c[(b[j])]=0) then 
	  	   begin
	  	   	write(j,' ');
	  	   	c[b[j]]:=1;
	  	   	break;
	  	   end;
	  end;
end.