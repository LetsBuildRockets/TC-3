scp -r ./* daq@TC-DAQ:/home/daq/tmp-TC-3/
plink.exe -ssh daq@TC-DAQ -i "C:\SPB_Data\.ssh\id_rsa.ppk"  "cd ~/tmp-TC-3 && make -j4 ALL"
