<script>
	/* Default to be 0 for sites except YouTube */
	ccCleanAtPlayItemURL = 0;

	/* Clean first */
	writeStringToFile("<?php echo $fileLocalExtraInfo; ?>", "");
	writeStringToFile("<?php echo $fileLocalCCStatus; ?>", "");
	writeStringToFile("<?php echo $fileLocalCCStatus; ?>", "");
	writeStringToFile("<?php echo $fileLocalCCEnd; ?>", "");
	writeStringToFile("<?php echo $fileLocalCCText; ?>", "");
	writeStringToFile("<?php echo $fileLocalCCCount; ?>", "0");

	bufferSize  = 262144;

	xmlUrl = getStoragePath("tmp") + "tmp.rss";
	writeStringToFile(xmlUrl, "ok");

	nameArray   = null;
	nameArray   = "<?php echo md5(time()); ?>";

	storagePath = getStoragePath("tmp");
	storagePath = storagePath + nameArray + ".dat";

<?php
	$pass_check = true;
	try {
		$itemTotal = 0;

		include($myBaseName . '.link.url.inc');
	}
	catch (Exception $e) {
		$pass_check = false;
	}

	if ($pass_check) {
		echo "\titemSize    = " . ($itemTotal) . ";\r\n";
		echo "\tlinkArray   = null;\r\n";
		echo "\ttitleArray  = null;\r\n";

		for ($i = 0 ; $i < $itemTotal ; $i ++) {
			echo "\tlinkArray   = pushBackStringArray(linkArray, \"" . $links[$i] . "\");\r\n";
			echo "\ttitleArray  = pushBackStringArray(titleArray, \"" . str_replace('"', '\"', $titles[$i]) . "\");\r\n";
		}
	}
?>
</script>
