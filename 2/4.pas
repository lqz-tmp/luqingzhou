var
  m,n,c,l,r,mid,tmp,ans:int64;
  i:longint;
  a:array[1..100000] of int64;
begin
	read(m,n);
	for i:=1 to m do begin read(a[i]); c:=c+a[i]; end;
	l:=1;
	r:=c div n;
	while (l<=r) do
	  begin
	  	mid:=(l+r) div 2;
	  	tmp:=0;
	  	for i:=1 to m do tmp:=tmp+(a[i] div mid);
	  	if tmp>=n then begin l:=mid+1;ans:=mid; end
	  	  else r:=mid-1;
	  end;
	write(ans);
end.
