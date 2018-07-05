var
	a,b,c,d: array[0..100000] of longint;
	n,k,i,cn,tmp,tem,ans:longint;
begin
	read(n,k);
	c[0]:=0;d[0]:=0;
	ans:=0;
	for i:=1 to n do read(a[i]);
	for i:=1 to n do read(b[i]);
	for i:=1 to n do
	  begin
	  	cn:=cn+a[i];
	  	c[i]:=cn;
	  end;
	cn:=0;
	for i:=1 to n do
	  begin
	  	if b[i]=1 then cn:=cn+a[i];
	  	d[i]:=cn;
	  end;
	for i:=1 to n-k+1 do
	  begin
	  	tmp:=c[i+k-1]-c[i-1]-(d[i+k-1]-d[i-1]);
	  	if tmp>ans then begin ans:=tmp;end;
	  end;
	write(ans+d[n]);
end.