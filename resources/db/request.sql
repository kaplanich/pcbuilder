SELECT
    c.id AS "ID",
    c.type AS "Type",
    c.name AS "Name",
    c.price AS "Price",
    c.img AS "Image",
    'CPU' AS "Category",

    cpu.cores AS "CPU Cores",
    cpu.threads AS "CPU Threads",
    cpu.base_clock AS "CPU Base Clock (GHz)",
    cpu.boost_clock AS "CPU Boost Clock (GHz)",
    cpu.tdp AS "CPU TDP (W)",

    CAST(NULL AS INTEGER) AS "GPU Memory (GB)",
    CAST(NULL AS REAL) AS "GPU Core Frequency (MHz)",
    CAST(NULL AS INTEGER) AS "GPU TDP (W)",
    CAST(NULL AS TEXT) AS "GPU Interface",

    CAST(NULL AS INTEGER) AS "RAM Capacity (GB)",
    CAST(NULL AS INTEGER) AS "RAM Speed (MHz)",
    CAST(NULL AS TEXT) AS "RAM Type",
    CAST(NULL AS INTEGER) AS "RAM Modules",

    CAST(NULL AS TEXT) AS "Motherboard Socket",
    CAST(NULL AS TEXT) AS "Motherboard Chipset",
    CAST(NULL AS TEXT) AS "Motherboard Form Factor",
    CAST(NULL AS INTEGER) AS "Motherboard RAM Slots",
    CAST(NULL AS INTEGER) AS "Motherboard Max RAM (GB)",

    CAST(NULL AS INTEGER) AS "Storage Capacity (GB)",
    CAST(NULL AS TEXT) AS "Storage Type",
    CAST(NULL AS TEXT) AS "Storage Interface",
    CAST(NULL AS INTEGER) AS "Storage Read Speed (MB/s)",
    CAST(NULL AS INTEGER) AS "Storage Write Speed (MB/s)",

    CAST(NULL AS TEXT) AS "Cooling Type",
    CAST(NULL AS REAL) AS "Cooling Noise Level (dB)",
    CAST(NULL AS REAL) AS "Cooling Radiator Size (mm)",
    CAST(NULL AS INTEGER) AS "Cooling Fan Count",

    CAST(NULL AS TEXT) AS "Case Form Factor",
    CAST(NULL AS TEXT) AS "Case Color",
    CAST(NULL AS TEXT) AS "Case Material",
    CAST(NULL AS INTEGER) AS "Case Fans Included",
    CAST(NULL AS INTEGER) AS "Case Max GPU Length (mm)",

    CAST(NULL AS INTEGER) AS "PSU Wattage (W)",
    CAST(NULL AS TEXT) AS "PSU Efficiency",
    CAST(NULL AS TEXT) AS "PSU Modular"
FROM Components c
JOIN CPU cpu ON c.id = cpu.component_id

UNION ALL

SELECT
    c.id AS "ID",
    c.type AS "Type",
    c.name AS "Name",
    c.price AS "Price",
    c.img AS "Image",
    'GPU' AS "Category",

    CAST(NULL AS INTEGER) AS "CPU Cores",
    CAST(NULL AS INTEGER) AS "CPU Threads",
    CAST(NULL AS REAL) AS "CPU Base Clock (GHz)",
    CAST(NULL AS REAL) AS "CPU Boost Clock (GHz)",
    CAST(NULL AS REAL) AS "CPU TDP (W)",

    gpu.memory AS "GPU Memory (GB)",
    gpu.core_frequency AS "GPU Core Frequency (MHz)",
    gpu.tdp AS "GPU TDP (W)",
    gpu.interface AS "GPU Interface",

    CAST(NULL AS INTEGER) AS "RAM Capacity (GB)",
    CAST(NULL AS INTEGER) AS "RAM Speed (MHz)",
    CAST(NULL AS TEXT) AS "RAM Type",
    CAST(NULL AS INTEGER) AS "RAM Modules",

    CAST(NULL AS TEXT) AS "Motherboard Socket",
    CAST(NULL AS TEXT) AS "Motherboard Chipset",
    CAST(NULL AS TEXT) AS "Motherboard Form Factor",
    CAST(NULL AS INTEGER) AS "Motherboard RAM Slots",
    CAST(NULL AS INTEGER) AS "Motherboard Max RAM (GB)",

    CAST(NULL AS INTEGER) AS "Storage Capacity (GB)",
    CAST(NULL AS TEXT) AS "Storage Type",
    CAST(NULL AS TEXT) AS "Storage Interface",
    CAST(NULL AS INTEGER) AS "Storage Read Speed (MB/s)",
    CAST(NULL AS INTEGER) AS "Storage Write Speed (MB/s)",

    CAST(NULL AS TEXT) AS "Cooling Type",
    CAST(NULL AS REAL) AS "Cooling Noise Level (dB)",
    CAST(NULL AS REAL) AS "Cooling Radiator Size (mm)",
    CAST(NULL AS INTEGER) AS "Cooling Fan Count",

    CAST(NULL AS TEXT) AS "Case Form Factor",
    CAST(NULL AS TEXT) AS "Case Color",
    CAST(NULL AS TEXT) AS "Case Material",
    CAST(NULL AS INTEGER) AS "Case Fans Included",
    CAST(NULL AS INTEGER) AS "Case Max GPU Length (mm)",

    CAST(NULL AS INTEGER) AS "PSU Wattage (W)",
    CAST(NULL AS TEXT) AS "PSU Efficiency",
    CAST(NULL AS TEXT) AS "PSU Modular"
FROM Components c
JOIN GPU gpu ON c.id = gpu.component_id

UNION ALL

SELECT
    c.id AS "ID",
    c.type AS "Type",
    c.name AS "Name",
    c.price AS "Price",
    c.img AS "Image",
    'RAM' AS "Category",

    CAST(NULL AS INTEGER) AS "CPU Cores",
    CAST(NULL AS INTEGER) AS "CPU Threads",
    CAST(NULL AS REAL) AS "CPU Base Clock (GHz)",
    CAST(NULL AS REAL) AS "CPU Boost Clock (GHz)",
    CAST(NULL AS REAL) AS "CPU TDP (W)",

    CAST(NULL AS INTEGER) AS "GPU Memory (GB)",
    CAST(NULL AS REAL) AS "GPU Core Frequency (MHz)",
    CAST(NULL AS INTEGER) AS "GPU TDP (W)",
    CAST(NULL AS TEXT) AS "GPU Interface",

    r.capacity AS "RAM Capacity (GB)",
    r.speed AS "RAM Speed (MHz)",
    r.type AS "RAM Type",
    r.modules AS "RAM Modules",

    CAST(NULL AS TEXT) AS "Motherboard Socket",
    CAST(NULL AS TEXT) AS "Motherboard Chipset",
    CAST(NULL AS TEXT) AS "Motherboard Form Factor",
    CAST(NULL AS INTEGER) AS "Motherboard RAM Slots",
    CAST(NULL AS INTEGER) AS "Motherboard Max RAM (GB)",

    CAST(NULL AS INTEGER) AS "Storage Capacity (GB)",
    CAST(NULL AS TEXT) AS "Storage Type",
    CAST(NULL AS TEXT) AS "Storage Interface",
    CAST(NULL AS INTEGER) AS "Storage Read Speed (MB/s)",
    CAST(NULL AS INTEGER) AS "Storage Write Speed (MB/s)",

    CAST(NULL AS TEXT) AS "Cooling Type",
    CAST(NULL AS REAL) AS "Cooling Noise Level (dB)",
    CAST(NULL AS REAL) AS "Cooling Radiator Size (mm)",
    CAST(NULL AS INTEGER) AS "Cooling Fan Count",

    CAST(NULL AS TEXT) AS "Case Form Factor",
    CAST(NULL AS TEXT) AS "Case Color",
    CAST(NULL AS TEXT) AS "Case Material",
    CAST(NULL AS INTEGER) AS "Case Fans Included",
    CAST(NULL AS INTEGER) AS "Case Max GPU Length (mm)",

    CAST(NULL AS INTEGER) AS "PSU Wattage (W)",
    CAST(NULL AS TEXT) AS "PSU Efficiency",
    CAST(NULL AS TEXT) AS "PSU Modular"
FROM Components c
JOIN RAM r ON c.id = r.component_id

UNION ALL

SELECT
    c.id AS "ID",
    c.type AS "Type",
    c.name AS "Name",
    c.price AS "Price",
    c.img AS "Image",
    'Motherboard' AS "Category",

    CAST(NULL AS INTEGER) AS "CPU Cores",
    CAST(NULL AS INTEGER) AS "CPU Threads",
    CAST(NULL AS REAL) AS "CPU Base Clock (GHz)",
    CAST(NULL AS REAL) AS "CPU Boost Clock (GHz)",
    CAST(NULL AS REAL) AS "CPU TDP (W)",

    CAST(NULL AS INTEGER) AS "GPU Memory (GB)",
    CAST(NULL AS REAL) AS "GPU Core Frequency (MHz)",
    CAST(NULL AS INTEGER) AS "GPU TDP (W)",
    CAST(NULL AS TEXT) AS "GPU Interface",

    CAST(NULL AS INTEGER) AS "RAM Capacity (GB)",
    CAST(NULL AS INTEGER) AS "RAM Speed (MHz)",
    CAST(NULL AS TEXT) AS "RAM Type",
    CAST(NULL AS INTEGER) AS "RAM Modules",

    m.socket AS "Motherboard Socket",
    m.chipset AS "Motherboard Chipset",
    m.form_factor AS "Motherboard Form Factor",
    m.ram_slots AS "Motherboard RAM Slots",
    m.max_ram AS "Motherboard Max RAM (GB)",

    CAST(NULL AS INTEGER) AS "Storage Capacity (GB)",
    CAST(NULL AS TEXT) AS "Storage Type",
    CAST(NULL AS TEXT) AS "Storage Interface",
    CAST(NULL AS INTEGER) AS "Storage Read Speed (MB/s)",
    CAST(NULL AS INTEGER) AS "Storage Write Speed (MB/s)",

    CAST(NULL AS TEXT) AS "Cooling Type",
    CAST(NULL AS REAL) AS "Cooling Noise Level (dB)",
    CAST(NULL AS REAL) AS "Cooling Radiator Size (mm)",
    CAST(NULL AS INTEGER) AS "Cooling Fan Count",

    CAST(NULL AS TEXT) AS "Case Form Factor",
    CAST(NULL AS TEXT) AS "Case Color",
    CAST(NULL AS TEXT) AS "Case Material",
    CAST(NULL AS INTEGER) AS "Case Fans Included",
    CAST(NULL AS INTEGER) AS "Case Max GPU Length (mm)",

    CAST(NULL AS INTEGER) AS "PSU Wattage (W)",
    CAST(NULL AS TEXT) AS "PSU Efficiency",
    CAST(NULL AS TEXT) AS "PSU Modular"
FROM Components c
JOIN Motherboard m ON c.id = m.component_id

UNION ALL

SELECT
    c.id AS "ID",
    c.type AS "Type",
    c.name AS "Name",
    c.price AS "Price",
    c.img AS "Image",
    'Storage' AS "Category",

    CAST(NULL AS INTEGER) AS "CPU Cores",
    CAST(NULL AS INTEGER) AS "CPU Threads",
    CAST(NULL AS REAL) AS "Base Clock (GHz)",
    CAST(NULL AS REAL) AS "Boost Clock (GHz)",
    CAST(NULL AS REAL) AS "CPU TDP (W)",

    CAST(NULL AS INTEGER) AS "GPU Memory (GB)",
    CAST(NULL AS REAL) AS "GPU Core Frequency (MHz)",
    CAST(NULL AS INTEGER) AS "GPU TDP (W)",
    CAST(NULL AS TEXT) AS "GPU Interface",

    CAST(NULL AS INTEGER) AS "RAM Capacity (GB)",
    CAST(NULL AS INTEGER) AS "RAM Speed (MHz)",
    CAST(NULL AS TEXT) AS "RAM Type",
    CAST(NULL AS INTEGER) AS "RAM Modules",

    CAST(NULL AS TEXT) AS "Motherboard Socket",
    CAST(NULL AS TEXT) AS "Chipset",
    CAST(NULL AS TEXT) AS "Form Factor",
    CAST(NULL AS INTEGER) AS "RAM Slots",
    CAST(NULL AS INTEGER) AS "Max Supported RAM (GB)",

    s.capacity AS "Storage Capacity (GB)",
    s.type AS "Storage Type",
    s.interface AS "Storage Interface",
    s.read_speed AS "Read Speed (MB/s)",
    s.write_speed AS "Write Speed (MB/s)",

    CAST(NULL AS TEXT) AS "Cooling Type",
    CAST(NULL AS REAL) AS "Noise Level (dB)",
    CAST(NULL AS REAL) AS "Radiator Size (mm)",
    CAST(NULL AS INTEGER) AS "Fan Count",

    CAST(NULL AS TEXT) AS "Case Form Factor",
    CAST(NULL AS TEXT) AS "Case Color",
    CAST(NULL AS TEXT) AS "Case Material",
    CAST(NULL AS INTEGER) AS "Included Fans",
    CAST(NULL AS INTEGER) AS "Max GPU Length (mm)",

    CAST(NULL AS INTEGER) AS "PSU Wattage (W)",
    CAST(NULL AS TEXT) AS "PSU Efficiency",
    CAST(NULL AS TEXT) AS "Modular Cabling"
FROM Components c
JOIN Storage s ON c.id = s.component_id

UNION ALL

SELECT
    c.id AS "ID",
    c.type AS "Type",
    c.name AS "Name",
    c.price AS "Price",
    c.img AS "Image",
    'Cooling' AS "Category",

    CAST(NULL AS INTEGER) AS "CPU Cores",
    CAST(NULL AS INTEGER) AS "CPU Threads",
    CAST(NULL AS REAL) AS "Base Clock (GHz)",
    CAST(NULL AS REAL) AS "Boost Clock (GHz)",
    CAST(NULL AS REAL) AS "CPU TDP (W)",

    CAST(NULL AS INTEGER) AS "GPU Memory (GB)",
    CAST(NULL AS REAL) AS "GPU Core Frequency (MHz)",
    CAST(NULL AS INTEGER) AS "GPU TDP (W)",
    CAST(NULL AS TEXT) AS "GPU Interface",

    CAST(NULL AS INTEGER) AS "RAM Capacity (GB)",
    CAST(NULL AS INTEGER) AS "RAM Speed (MHz)",
    CAST(NULL AS TEXT) AS "RAM Type",
    CAST(NULL AS INTEGER) AS "RAM Modules",

    CAST(NULL AS TEXT) AS "Motherboard Socket",
    CAST(NULL AS TEXT) AS "Chipset",
    CAST(NULL AS TEXT) AS "Form Factor",
    CAST(NULL AS INTEGER) AS "RAM Slots",
    CAST(NULL AS INTEGER) AS "Max Supported RAM (GB)",

    CAST(NULL AS INTEGER) AS "Storage Capacity (GB)",
    CAST(NULL AS TEXT) AS "Storage Type",
    CAST(NULL AS TEXT) AS "Storage Interface",
    CAST(NULL AS INTEGER) AS "Read Speed (MB/s)",
    CAST(NULL AS INTEGER) AS "Write Speed (MB/s)",

    co.type AS "Cooling Type",
    co.noise_level AS "Noise Level (dB)",
    co.radiator_size AS "Radiator Size (mm)",
    co.fan_count AS "Fan Count",

    CAST(NULL AS TEXT) AS "Case Form Factor",
    CAST(NULL AS TEXT) AS "Case Color",
    CAST(NULL AS TEXT) AS "Case Material",
    CAST(NULL AS INTEGER) AS "Included Fans",
    CAST(NULL AS INTEGER) AS "Max GPU Length (mm)",

    CAST(NULL AS INTEGER) AS "PSU Wattage (W)",
    CAST(NULL AS TEXT) AS "PSU Efficiency",
    CAST(NULL AS TEXT) AS "Modular Cabling"
FROM Components c
JOIN Cooling co ON c.id = co.component_id

UNION ALL

SELECT
    c.id AS "ID",
    c.type AS "Type",
    c.name AS "Name",
    c.price AS "Price",
    c.img AS "Image",
    'Case' AS "Category",

    CAST(NULL AS INTEGER) AS "CPU Cores",
    CAST(NULL AS INTEGER) AS "CPU Threads",
    CAST(NULL AS REAL) AS "Base Clock (GHz)",
    CAST(NULL AS REAL) AS "Boost Clock (GHz)",
    CAST(NULL AS REAL) AS "CPU TDP (W)",

    CAST(NULL AS INTEGER) AS "GPU Memory (GB)",
    CAST(NULL AS REAL) AS "GPU Core Frequency (MHz)",
    CAST(NULL AS INTEGER) AS "GPU TDP (W)",
    CAST(NULL AS TEXT) AS "GPU Interface",

    CAST(NULL AS INTEGER) AS "RAM Capacity (GB)",
    CAST(NULL AS INTEGER) AS "RAM Speed (MHz)",
    CAST(NULL AS TEXT) AS "RAM Type",
    CAST(NULL AS INTEGER) AS "RAM Modules",

    CAST(NULL AS TEXT) AS "Motherboard Socket",
    CAST(NULL AS TEXT) AS "Chipset",
    CAST(NULL AS TEXT) AS "Form Factor",
    CAST(NULL AS INTEGER) AS "RAM Slots",
    CAST(NULL AS INTEGER) AS "Max Supported RAM (GB)",

    CAST(NULL AS INTEGER) AS "Storage Capacity (GB)",
    CAST(NULL AS TEXT) AS "Storage Type",
    CAST(NULL AS TEXT) AS "Storage Interface",
    CAST(NULL AS INTEGER) AS "Read Speed (MB/s)",
    CAST(NULL AS INTEGER) AS "Write Speed (MB/s)",

    CAST(NULL AS TEXT) AS "Cooling Type",
    CAST(NULL AS REAL) AS "Noise Level (dB)",
    CAST(NULL AS REAL) AS "Radiator Size (mm)",
    CAST(NULL AS INTEGER) AS "Fan Count",

    cc.form_factor AS "Case Form Factor",
    cc.color AS "Case Color",
    cc.material AS "Case Material",
    cc.fans_included AS "Included Fans",
    cc.max_gpu_length AS "Max GPU Length (mm)",

    CAST(NULL AS INTEGER) AS "PSU Wattage (W)",
    CAST(NULL AS TEXT) AS "PSU Efficiency",
    CAST(NULL AS TEXT) AS "Modular Cabling"
FROM Components c
JOIN CaseComponent cc ON c.id = cc.component_id

UNION ALL

SELECT
    c.id AS "ID",
    c.type AS "Type",
    c.name AS "Name",
    c.price AS "Price",
    c.img AS "Image",
    'PSU' AS "Category",

    CAST(NULL AS INTEGER) AS "CPU Cores",
    CAST(NULL AS INTEGER) AS "CPU Threads",
    CAST(NULL AS REAL) AS "Base Clock (GHz)",
    CAST(NULL AS REAL) AS "Boost Clock (GHz)",
    CAST(NULL AS REAL) AS "CPU TDP (W)",

    CAST(NULL AS INTEGER) AS "GPU Memory (GB)",
    CAST(NULL AS REAL) AS "GPU Core Frequency (MHz)",
    CAST(NULL AS INTEGER) AS "GPU TDP (W)",
    CAST(NULL AS TEXT) AS "GPU Interface",

    CAST(NULL AS INTEGER) AS "RAM Capacity (GB)",
    CAST(NULL AS INTEGER) AS "RAM Speed (MHz)",
    CAST(NULL AS TEXT) AS "RAM Type",
    CAST(NULL AS INTEGER) AS "RAM Modules",

    CAST(NULL AS TEXT) AS "Motherboard Socket",
    CAST(NULL AS TEXT) AS "Chipset",
    CAST(NULL AS TEXT) AS "Form Factor",
    CAST(NULL AS INTEGER) AS "RAM Slots",
    CAST(NULL AS INTEGER) AS "Max Supported RAM (GB)",

    CAST(NULL AS INTEGER) AS "Storage Capacity (GB)",
    CAST(NULL AS TEXT) AS "Storage Type",
    CAST(NULL AS TEXT) AS "Storage Interface",
    CAST(NULL AS INTEGER) AS "Read Speed (MB/s)",
    CAST(NULL AS INTEGER) AS "Write Speed (MB/s)",

    CAST(NULL AS TEXT) AS "Cooling Type",
    CAST(NULL AS REAL) AS "Noise Level (dB)",
    CAST(NULL AS REAL) AS "Radiator Size (mm)",
    CAST(NULL AS INTEGER) AS "Fan Count",

    CAST(NULL AS TEXT) AS "Case Form Factor",
    CAST(NULL AS TEXT) AS "Case Color",
    CAST(NULL AS TEXT) AS "Case Material",
    CAST(NULL AS INTEGER) AS "Included Fans",
    CAST(NULL AS INTEGER) AS "Max GPU Length (mm)",

    p.wattage AS "PSU Wattage (W)",
    p.efficiency AS "PSU Efficiency",
    p.modular AS "Modular Cabling"
FROM Components c
JOIN PSU p ON c.id = p.component_id;
