hold off
clf('reset')
[data text]=importdata('data/dat_68.csv');

len = 20;
b = ones(len,1)/len;
m = [6,14,16];
for n = m
    col1 = data.data(:, n+1);
    I = ~isnan(col1);
    x= 1:length(col1);
    hold on
    plot(filter(b,1,flip(filter(b,1,flip(col1(I))))) ,'-')
end
axis tight
legend(string(m))