var
	i,j,n,tmp,sum,cn,te,fl: longint;
	a:array[1..200000]of longint;
	m:array[-200000..200000,1..2] of longint;
begin
	readln(n);
	for i:=1 to n do 
	  begin
	    if fl=-1 then break; 
	  	readln(tmp);
	  	sum:=0;
	  	for j:=1 to tmp do begin read(a[j]);sum:=sum+a[j];end;
	  	for j:=1 to tmp do begin
	  		te:=sum-a[j];
	  		if te<-200000 then te:=-1*te mod 200000;
	  		if (m[te,1]<>0)and(m[te,1]<>i) then begin writeln('YES');writeln(m[te,1],' ',m[te,2]);writeln(i,' ',j);fl:=-1;break;end
	  		else begin m[te,1]:=i;m[te,2]:=j;end;
	  	end;
	  end;
	if fl<>-1 then writeln('NO');
end.