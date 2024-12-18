file(READ "${INPUT}" pc_json)

string(JSON uuid_arr GET "${pc_json}" PipelineUUID)
foreach(uuid_idx RANGE 0 15)
    string(JSON uuid_val GET "${uuid_arr}" ${uuid_idx})
    list(APPEND uuid_vals ${uuid_val})
endforeach(uuid_idx RANGE 0 15)

list(JOIN uuid_vals "," uuid_string)
file(WRITE "${OUTPUT}" ${uuid_string})