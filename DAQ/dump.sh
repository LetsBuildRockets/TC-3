#!/bin/bash
mkdir data
TEST_NUM=$1;
psql -h TC-DAQ -U daq -d DAQDATA -A -F "," -c "
 SELECT to_char(data_timestamp,'SSSS.US') AS TIME, *
 FROM crosstab(
	'SELECT data_timestamp, sensor_id, scaled_data
	 FROM testdata
	 WHERE test_num=$TEST_NUM
	 ORDER BY 1,2'
     , \$\$ SELECT unnest('{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31}'::text[])\$\$
     )
 AS res(
	data_timestamp timestamp without time zone,
        \"0\" double precision,
        \"1\" double precision,
        \"2\" double precision,
        \"3\" double precision,
        \"4\" double precision,
        \"5\" double precision,
        \"6\" double precision,
        \"7\" double precision,
        \"8\" double precision,
        \"9\" double precision,
        \"10\" double precision,
        \"11\" double precision,
        \"12\" double precision,
        \"13\" double precision,
        \"14\" double precision,
        \"15\" double precision,
        \"16\" double precision,
        \"17\" double precision,
        \"18\" double precision,
        \"19\" double precision,
        \"20\" double precision,
        \"21\" double precision,
        \"22\" double precision,
        \"23\" double precision,
        \"24\" double precision,
        \"25\" double precision,
        \"26\" double precision,
        \"27\" double precision,
        \"28\" double precision,
        \"29\" double precision,
        \"30\" double precision,
        \"31\" double precision);
" -o data/dat_$TEST_NUM.csv --pset footer