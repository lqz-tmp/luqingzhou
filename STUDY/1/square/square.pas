var
  n,m,a,b,c:longint;
begin
  assign(input,'square.in');
  reset(input);
  assign(output,'square.out');
  rewrite(output);
  read(n,m,a);
  b:=n div a;
  c:=m div a;
  if n mod a<>0 then b:=b+1;
  if m mod a<>0 then c:=c+1;
  b:=b*c;
  write(b);
  close(input);
  close(output);
end.
