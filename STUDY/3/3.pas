var
	n,c,cn,q,l,r:int64;
	i:longint;
	a,b:array[0..100000] of int64;
begin
	read(n,c);
	for i:=1 to n do read(a[i]);
	read(q);
	for i:=1 to n do 
	  begin
	  	cn:=cn+a[i];
	  	b[i]:=cn;
	  end;
	for i:=1 to q do
	  begin
	  read(l,r);
	  if (b[r]-b[l-1]) mod c=0 then
	  writeln((b[r]-b[l-1])div c)
	  else writeln((b[r]-b[l-1])div c +1);
	  end;
end.