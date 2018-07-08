var 
 n,i,tmp,ans,te:longint;
 a,b:array[1..10000]of longint;
procedure qsort(l,r: longint);
  var
     i,j,mid,y: longint;
  begin
     i:=l;
     j:=r;
     mid:=a[(l+r) div 2];
     repeat
       while a[i]<mid do
        inc(i);
       while mid<a[j] do
        dec(j);
       if i<=j then
         begin
            y:=a[i];
            a[i]:=a[j];
            a[j]:=y;
            i:=i+1;
            j:=j-1;
         end;
     until i>j;
     if l<j then
       qsort(l,j);
     if i<r then
       qsort(i,r);
  end;
procedure sort(l,r: longint);
  var
     i,j,mid,y: longint;
  begin
     i:=l;
     j:=r;
     mid:=b[(l+r) div 2];
     repeat
       while b[i]<mid do
        inc(i);
       while mid<b[j] do
        dec(j);
       if i<=j then
         begin
            y:=b[i];
            b[i]:=b[j];
            b[j]:=y;
            i:=i+1;
            j:=j-1;
         end;
     until i>j;
     if l<j then
       sort(l,j);
     if i<r then
       sort(i,r);
  end;
begin
	read(n);
	for i:=1 to n do read(b[i],a[i]);
	qsort(1,n);sort(1,n);
	tmp:=a[(n div 2) +1];
	for i:=1 to n do ans:=ans+abs(a[i]-tmp);
  for i:=1 to n do a[i]:=b[i]-i+1;
  qsort(1,n);
  te:=(n div 2)+1;
  tmp:=a[te];
  for i:=1 to n do ans:=ans+abs(a[i]-tmp);
  write(ans);
end.