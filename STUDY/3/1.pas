var
	i,j,n,k,d,tmp,ans,cn: Integer;
	a,b:array[0..1000] of integer;
begin
	read(n,k,d);
        b[0]:=0;
	ans:=maxInt;
	for i:=1 to d do
	  begin
	  	read(tmp);
        a[tmp]:=1;
	  end;
	for i:=1 to n do
	  begin
	  	if a[i]=1 then begin cn:=cn+1; b[i]:=cn; end else b[i]:=cn;
	  end;
       for i:=1 to n-k+1 do
         begin
         	tmp:=b[i+k-1]-b[i-1];
         	if tmp<ans then ans:=tmp;
         end;
       write(ans);
       //for i:=1 to n do write('  ',b[i]);
end.
