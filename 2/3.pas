var
 n,m,max,min,l,r,mid,tmp,ans:int64;
 i:longint;
 a:array[1..100000] of longint;
begin
	read(n,m);
	min:=100000;
	for i:=1 to n do begin read(a[i]); if a[i]>max then max:=a[i]; if a[i]<min then min:=a[i]; end;
	l:=min;
	r:=max*m;
	while (l<=r) do
	  begin
	  	mid:=(l+r) div 2;
	  	tmp:=0;
	  	for i:=1 to n do tmp:=tmp+(mid div a[i]);
	  	if tmp>=m then begin r:=mid-1; ans:=mid; end
	  	 else l:=mid+1;
	  end;
        write(ans);
end.
