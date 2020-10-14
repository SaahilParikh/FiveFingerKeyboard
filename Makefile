test:
	ls ./in| awk '{print}' | python ./in/file.py >> output