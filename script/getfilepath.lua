local lfs = require("lfs")
function getFileCreationTime(filePath)
    local attr = lfs.attributes(filePath)
    print(attr.modification)
    return attr.modification
  
end

function getAllFilesInDirectory(directory)
    local files = {}
    for file in lfs.dir(directory) do
        if file ~= "." and file ~= ".." then
            local filePath = directory .. "/" .. file
            local attr = lfs.attributes(filePath)
            if attr.mode == "file" then
                table.insert(files, filePath)
            end
        end
    end
    return files
end

-- Usage
local directory = "src"
local files = getAllFilesInDirectory(directory)
for _, file in ipairs(files) do
    print(file)
    local modificationTime = getFileCreationTime(file)
    if modificationTime then
        print("File modification time (Unix timestamp):", modificationTime)
    else
        print("Failed to get file modification time")
    end
end