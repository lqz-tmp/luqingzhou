var 
  i,n,tt,tr,tl:longint;
  ans:int64;
  a,tmp:array[0..1000000] of longint;
procedure merge(p,q,r:longint);
    begin
        tt:=p;
        tl:=p;
        tr:=q+1;
        while (tl<=q)or(tr<=r) do
         if (tl>q)or((tr<=r)and(a[tl]>a[tr])) then
          begin
          	tmp[tt]:=a[tr];
          	inc(tr);
          	inc(tt);
          end
         else
          begin
          	tmp[tt]:=a[tl];
          	inc(tl);
          	inc(tt);
          	ans:=ans+tr-q-1;
          end;
        for i:=p to r do a[i]:=tmp[i];
    end;
procedure msort(p,r:longint);
    var
        q:longint;
    begin
      if p<>r then
       begin
        q:=(p+r-1) div 2;
        msort(p,q);
        msort(q+1,r);
        merge(p,q,r)
       end;
    end;
begin
	read(n);
	for i:=1 to n do read(a[i]);
	msort(1,n);
	writeln(ans);
end.