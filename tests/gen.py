files = [
    "types/Face_getArea",
    "types/Face_getPerimetr",
    
    "ParallelepipedShape_getSurfaceArea",
    "ParallelepipedShape_getVolume",
    
    "PrismShape_getVolume",
    "PrismShape_getSurfaceArea",
    
    "PyramidShape_getVolume",
    "PyramidShape_getSurfaceArea",
]

data = '#include "unit_test.hpp"\n\nint main() {\n    //TODO: Add body\n}'

for f in files:
    o = open(f + ".cpp", "w")
    o.write(data)
    o.close()