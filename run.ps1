param (
    [Parameter(Mandatory = $true)]
    [string[]]$Files
)

$compiledFolder = "compiled"
if (-not (Test-Path -Path $compiledFolder)) {
    New-Item -ItemType Directory -Path $compiledFolder | Out-Null
}

foreach ($file in $Files) {
    $filename = [System.IO.Path]::GetFileNameWithoutExtension($file)
    $output = "$compiledFolder\$filename.exe"
    $buildCommand = "g++ $file -o $output"
    $buildResult = Invoke-Expression $buildCommand
    if ($buildResult) {
        Write-Host "Build failed for file: $file"
        continue
    }

    $runCommand = ".\$output"
    try {
        $startTime = Get-Date
        Invoke-Expression $runCommand
        $endTime = Get-Date
        $elapsedTime = $endTime - $startTime
        Write-Host "Run succeeded for file: $file, elapsed time: $($elapsedTime.TotalMilliseconds) miliseconds"
    }
    catch {
        Write-Host "Run failed for file: $file"
    }
    
    if (Test-Path -Path $output) {
        Remove-Item -Path $output
    }
}
