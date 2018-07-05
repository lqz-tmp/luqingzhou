var
	i,j,n,m,l,r:longint;
	a,b:array[0..500000] of longint;
begin
	readln(n);
	for i:=1 to n do 
	 begin
	 	readln(l,r);
	 	a[l]:=a[l]+1;
	 	a[r+1]:=a[r+1]-1;
	 end;
	b[0]:=a[0];
	for i:=1 to 500000 do 
	  b[i]:=b[i-1]+a[i];
	readln(m);
	for i:=1 to m do
	 begin
	 	readln(j);
	 	writeln(b[j]);
	 end;
end.