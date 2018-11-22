hold off
clf('reset')
[data text]=importdata('data/dat_80.csv');
x= str2double(data.textdata(:,1));
x=x-x(2);
len = 10;
b = ones(len,1)/len;
m = [6,14,16];
for n = m
    col1 = data.data(:, n+1);
    I = ~isnan(col1) & ~isnan(x);
    hold on
    plot(x(I), filter(b,1,flip(filter(b,1,flip(col1(I))))) ,'-')
end
axis tight
legend(string(m))