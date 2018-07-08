var
  n,m,i,j,k,tmp,ti,tj,cn:longint;
  a:array[0..300,0..300]of longint;
function min(a,b:longint): longint;
begin
	if a>b then a:=b;
	exit(a);
end;
begin
	read(n,m);
	for i:=1 to n do 
	  for j:=1 to m do read(a[i,j]);
	for i:=1 to n do
	  for j:=1 to m do
	    a[i,j]:=a[i-1,j]+a[i,j-1]+a[i,j]-a[i-1,j-1];
	for i:=1 to n-1 do
	  for j := 1 to m do
	    for k := 2 to min(n-i+1,m-j+1) do
	    begin
	        ti:=i+k-1;
	        tj:=j+k-1;
	    	tmp:=a[ti,tj]-a[i-1,tj]-a[ti,j-1]+a[i-1,j-1];
	    	if abs(k*k-tmp*2)<=1 then cn:=cn+1;
	    end;
	write(cn);
end.