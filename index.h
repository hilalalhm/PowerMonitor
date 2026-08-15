#ifndef INDEX_H
#define INDEX_H

const char html_page[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no">
    <title>Monitor Listrik</title>
    <style>
        * { 
            box-sizing: border-box; 
            margin: 0; 
            padding: 0; 
        }
        body { 
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Helvetica, Arial, sans-serif; 
            background-color: #f4f6f9; 
            color: #202124; 
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            padding: 15px;
        }
        .container { 
            width: 100%; 
            max-width: 550px; 
            background: #ffffff;
            padding: 24px 20px;
            border-radius: 16px;
            box-shadow: 0 10px 25px rgba(0, 0, 0, 0.06);
        }
        .header {
            text-align: center;
            margin-bottom: 20px;
            padding-bottom: 12px;
            border-bottom: 2px solid #f0f2f5;
        }
        .header h2 {
            font-size: 1.3rem;
            color: #1a73e8;
            font-weight: 700;
            letter-spacing: 0.5px;
        }
        .header p {
            font-size: 0.8rem;
            color: #5f6368;
            margin-top: 4px;
        }
        .status-badge {
            display: inline-flex;
            align-items: center;
            gap: 6px;
            background: #e6f4ea;
            color: #137333;
            font-size: 0.75rem;
            padding: 4px 12px;
            border-radius: 20px;
            margin-top: 8px;
            font-weight: 600;
        }
        .dot {
            width: 8px;
            height: 8px;
            background-color: #34a853;
            border-radius: 50%;
            display: inline-block;
            animation: pulse 1.5s infinite;
        }

        .grid-container { 
            display: grid; 
            grid-template-columns: repeat(2, 1fr); 
            gap: 14px; 
        }
        .card { 
            background: #ffffff; 
            padding: 18px 12px; 
            border-radius: 12px; 
            text-align: center; 
            border: 1px solid #e8eaed;
            border-top: 4px solid #1a73e8;
            box-shadow: 0 2px 6px rgba(0,0,0,0.02);
            transition: all 0.2s ease;
        }
        /* Color accent untuk tiap parameter */
        .card:nth-child(1) { border-top-color: #1a73e8; } /* Tegangan - Biru */
        .card:nth-child(2) { border-top-color: #34a853; } /* Arus - Hijau */
        .card:nth-child(3) { border-top-color: #fbbc04; } /* Daya - Kuning */
        .card:nth-child(4) { border-top-color: #ea4335; } /* Energi - Merah */

        .card h3 { 
            font-size: 0.75rem; 
            text-transform: uppercase; 
            letter-spacing: 0.8px; 
            color: #5f6368; 
            margin-bottom: 6px; 
        }
        .card .value { 
            font-size: 1.6rem; 
            font-weight: 700; 
            color: #202124; 
            line-height: 1.2;
        }
        .card .unit { 
            font-size: 0.8rem; 
            color: #80868b; 
            margin-top: 4px;
        }

        /* Responsive Breakpoint: Layar Sangat Kecil / HP Jadul (di bawah 360px) */
        @media (max-width: 360px) {
            .grid-container {
                grid-template-columns: 1fr; /* Berubah menjadi 1 kolom tumpuk */
            }
            .card .value {
                font-size: 1.8rem;
            }
        }

        @keyframes pulse {
            0% { opacity: 1; }
            50% { opacity: 0.4; }
            100% { opacity: 1; }
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <h2>MONITOR LISTRIK</h2>
            <div class="status-badge">
                <span class="dot"></span> Live 
            </div>
        </div>

        <div class="grid-container">
            <div class="card">
                <h3>Tegangan</h3>
                <div class="value" id="vol">0.0</div>
                <div class="unit">Volt (V)</div>
            </div>
            <div class="card">
                <h3>Arus</h3>
                <div class="value" id="cur">0.00</div>
                <div class="unit">Ampere (A)</div>
            </div>
            <div class="card">
                <h3>Daya</h3>
                <div class="value" id="pow">0.0</div>
                <div class="unit">Watt (W)</div>
            </div>
            <div class="card">
                <h3>Energi</h3>
                <div class="value" id="ene">0.00</div>
                <div class="unit">kWh</div>
            </div>
        </div>
    </div>

    <script>
        function updateData() {
            fetch('/data')
            .then(res => res.json())
            .then(data => {
                document.getElementById('vol').innerText = data.v.toFixed(1);
                document.getElementById('cur').innerText = data.i.toFixed(2);
                document.getElementById('pow').innerText = data.p.toFixed(1);
                document.getElementById('ene').innerText = data.e.toFixed(2);
            })
            .catch(err => console.error("Gagal mengambil data:", err));
        }

        // Panggil data setiap 2 detik
        setInterval(updateData, 2000);
    </script>
</body>
</html>
)rawliteral";

#endif